--- charconv.cpp.orig	2015-01-29 23:00:00 UTC
+++ charconv.cpp
@@ -109,7 +109,7 @@ namespace charset {
 
     bool recode(char* out, size_t avail, const void* src, size_t len, const char* to, const char* from)
     {
-        const char* in = (const char*)src;
+        char* in = (char*)src;
 
         iconv_t cvt = iconv_open(to, from);
         if(cvt == (iconv_t)-1)
