--- src/rapidfuzz/utils.hpp.orig	2024-08-06 20:55:30 UTC
+++ src/rapidfuzz/utils.hpp
@@ -10,7 +10,7 @@
 #include <cwctype>
 #include <limits>
 #include <stdint.h>
-#include <string>
+#include <vector>
 
 uint32_t UnicodeDefaultProcess(uint32_t ch);
 
@@ -80,11 +80,9 @@ template <typename CharT>
 }
 
 template <typename CharT>
-std::basic_string<CharT> default_process(std::basic_string<CharT> s)
+std::vector<CharT> default_process(std::vector<CharT> str)
 {
-    std::basic_string<CharT> str(s);
-
-    int64_t len = default_process(&str[0], str.size());
+    int64_t len = default_process(str.data(), str.size());
     str.resize(len);
     return str;
 }
