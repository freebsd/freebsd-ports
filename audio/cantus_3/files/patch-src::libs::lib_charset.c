--- src/libs/lib_charset.c.orig	Tue May 18 14:25:50 2004
+++ src/libs/lib_charset.c	Tue May 18 14:25:59 2004
@@ -207,7 +207,7 @@
   outptr  = out;
   
 retry:
-  if (iconv(cd, (char**)&input, &length, &outptr, &outleft) == -1) {
+  if (iconv(cd, (const char**)&input, &length, &outptr, &outleft) == -1) {
     int used;
     switch (errno) {
     case E2BIG:
