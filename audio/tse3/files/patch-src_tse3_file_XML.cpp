--- src/tse3/file/XML.cpp.orig	2005-08-23 12:32:53 UTC
+++ src/tse3/file/XML.cpp
@@ -110,7 +110,7 @@ void TSE3::File::XmlFileWriter::element(
 }
 
 
-void TSE3::File::XmlFileWriter::element(const std::string &name, unsigned int value)
+void TSE3::File::XmlFileWriter::element(const std::string &name, size_t value)
 {
     indent(out);
     out << "<" << name << " value=\"" << value << "\"/>\n";
