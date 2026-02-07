--- libs/xml/xmlparser.h.orig	2013-06-30 22:04:34.000000000 +0800
+++ libs/xml/xmlparser.h	2013-12-15 01:59:46.000000000 +0800
@@ -102,12 +102,14 @@ inline TextOutputStreamType& ostream_wri
 	return ostream;
 }
 
+#if 0
 template<typename TextOutputStreamType>
 inline TextOutputStreamType& ostream_write( TextOutputStreamType& ostream, const Formatted& formatted ){
 	char buffer[1024];
 	ostream.write( buffer, vsnprintf( buffer, 1023, formatted.m_format, formatted.m_arguments ) );
 	return ostream;
 }
+#endif
 
 class XMLSAXImporter
 {
