--- ../db/xml_util.h.orig	Wed Jun 30 16:52:29 2004
+++ ../db/xml_util.h	Sun Oct  3 21:16:22 2004
@@ -223,7 +223,7 @@
 template <typename T>
 inline std::string xml_encode_string(const std::vector<T> &input,
     xml_encoding encoding=_x_xml_entity) {
-  return xml_encode_string<T>(&(*(input.begin())),input.size(),encoding);
+  return xml_encode_string(&(*(input.begin())),input.size(),encoding);
 }
 
 #include <cctype>
