
$FreeBSD$

--- plm/metadata/id3v2/io_helpers.cpp.orig	Sat Dec 21 18:10:14 2002
+++ plm/metadata/id3v2/io_helpers.cpp	Sat Dec 21 18:11:59 2002
@@ -290,11 +290,11 @@
   return writer.writeChars(bytes, size);
 }
 
-ID3_Writer::size_type io::writeTrailingSpaces(ID3_Writer& writer, String buf, size_t len)
+size_t io::writeTrailingSpaces(ID3_Writer& writer, String buf, size_t len)
 {
   ID3_Writer::pos_type beg = writer.getCur();
   ID3_Writer::size_type strLen = buf.size();
-  ID3_Writer::size_type size = min(len, strLen);
+  ID3_Writer::size_type size = min((unsigned int)len, (unsigned int)strLen);
   writer.writeChars(buf.data(), size);
   for (; size < len; ++size)
   {
