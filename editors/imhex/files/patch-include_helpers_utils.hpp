--- include/helpers/utils.hpp.orig	2020-12-06 20:40:57 UTC
+++ include/helpers/utils.hpp
@@ -61,6 +61,7 @@ namespace hex {
 
     std::string toByteString(u64 bytes);
     std::string makePrintable(char c);
+    std::string demangle(const std::string &mangled_name);
 
     template<typename T>
     struct always_false : std::false_type {};
