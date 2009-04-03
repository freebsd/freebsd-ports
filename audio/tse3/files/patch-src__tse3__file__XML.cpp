--- src/tse3/file/XML.cpp	Tue Aug 23 08:32:53 2005
+++ src/tse3/file/XML.cpp	Sun Sep 11 20:29:22 2005
@@ -111,5 +111,5 @@
 
 
-void TSE3::File::XmlFileWriter::element(const std::string &name, unsigned int value)
+void TSE3::File::XmlFileWriter::element(const std::string &name, size_t value)
 {
     indent(out);
