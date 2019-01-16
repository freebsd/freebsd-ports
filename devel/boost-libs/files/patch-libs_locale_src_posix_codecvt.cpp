--- libs/locale/src/posix/codecvt.cpp.orig	2017-09-02 09:56:14 UTC
+++ libs/locale/src/posix/codecvt.cpp
@@ -38,7 +38,7 @@ namespace impl_posix {
             iconv_t d = (iconv_t)(-1);
             std::vector<uint32_t> first_byte_table;
             try {
-                d = iconv_open(utf32_encoding(),encoding.c_str());
+                d = call_iconv_open(utf32_encoding(),encoding.c_str());
                 if(d == (iconv_t)(-1)) {
                     throw std::runtime_error("Unsupported encoding" + encoding);
                 }
@@ -186,7 +186,7 @@ namespace impl_posix {
         {
             if(d!=(iconv_t)(-1))
                 return;
-            d=iconv_open(to,from);
+            d=call_iconv_open(to,from);
         }
 
         static char const *utf32_encoding()
