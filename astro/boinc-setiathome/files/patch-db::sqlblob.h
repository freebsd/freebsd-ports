--- ../db/sqlblob.h.orig	Thu Jul  1 13:55:37 2004
+++ ../db/sqlblob.h	Sun Oct  3 17:01:17 2004
@@ -73,6 +73,12 @@
 }
 
        
+template <typename T>
+inline std::string xml_encode_string(const sqlblob<T> &input, 
+    xml_encoding encoding=_x_xml_entity) {
+  return xml_encode_string(static_cast<const T *>(input),input.size(),encoding);
+}
+
 
 template <typename T=unsigned char>
 class sqlblob {
@@ -123,12 +129,6 @@
 template <typename T>
 std::string sqlblob<T>::print_raw() const {
   return std::string(reinterpret_cast<const char *>(&(*begin())),size());
-}
-
-template <typename T>
-inline std::string xml_encode_string(const sqlblob<T> &input, 
-    xml_encoding encoding=_x_xml_entity) {
-  return xml_encode_string(static_cast<const T *>(input),input.size(),encoding);
 }
 
 
