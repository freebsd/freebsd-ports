--- config.tests/unix/gnu-libiconv/gnu-libiconv.cpp.orig	2014-04-10 18:37:08 UTC
+++ config.tests/unix/gnu-libiconv/gnu-libiconv.cpp
@@ -48,7 +48,7 @@ int main(int, char **)
 {
     iconv_t x = iconv_open("", "");
 
-    const char *inp;
+    char *inp;
     char *outp;
     size_t inbytes, outbytes;
     iconv(x, &inp, &inbytes, &outp, &outbytes);
