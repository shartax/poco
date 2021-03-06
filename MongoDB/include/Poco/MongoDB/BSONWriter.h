//
// BSONWriter.h
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  BSONWriter
//
// Definition of the BSONWriter class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef MongoDB_BSONWriter_INCLUDED
#define MongoDB_BSONWriter_INCLUDED


#include "Poco/MongoDB/MongoDB.h"
#include "Poco/BinaryWriter.h"


namespace Poco {
namespace MongoDB {


class MongoDB_API BSONWriter
	/// Class for writing BSON to a Poco::BinaryWriter.
{
public:
	BSONWriter(const Poco::BinaryWriter& writer) : _writer(writer)
		/// Constructor
	{
	}

	virtual ~BSONWriter()
		/// Destructor
	{
	}

	template<typename T>
	void write(T& t)
		/// Writes the value to the writer. The default implementation uses
		/// the << operator. Special types can write their own version.
	{
		_writer << t;
	}

	void writeCString(const std::string& value);
		/// Writes a cstring to the writer. A cstring is a string
		/// terminated with 0x00

private:
	Poco::BinaryWriter _writer;
};


inline void BSONWriter::writeCString(const std::string& value)
{
	_writer.writeRaw(value);
	_writer << (unsigned char) 0x00;
}


} } // namespace Poco::MongoDB


#endif //  MongoDB_BSONWriter_INCLUDED
