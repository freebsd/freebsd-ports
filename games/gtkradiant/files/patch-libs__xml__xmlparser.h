--- libs/xml/xmlparser.h.orig	2006-02-11 06:01:20.000000000 +0800
+++ libs/xml/xmlparser.h	2013-12-15 02:23:59.000000000 +0800
@@ -113,6 +113,7 @@ inline TextOutputStreamType& ostream_wri
   return ostream;
 }
 
+#if 0
 template<typename TextOutputStreamType>
 inline TextOutputStreamType& ostream_write(TextOutputStreamType& ostream, const Formatted& formatted)
 {
@@ -120,6 +121,7 @@ inline TextOutputStreamType& ostream_wri
   ostream.write(buffer, vsnprintf(buffer, 1023, formatted.m_format, formatted.m_arguments));
   return ostream;
 }
+#endif
 
 class XMLSAXImporter
 {
