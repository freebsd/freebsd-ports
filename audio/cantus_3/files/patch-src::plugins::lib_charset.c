--- src/plugins/lib_charset.c.orig	Tue May 18 14:17:18 2004
+++ src/plugins/lib_charset.c	Tue May 18 14:17:34 2004
@@ -191,7 +191,7 @@
   outptr  = out;
   
 retry:
-  if (iconv(cd, (char**)&input, &length, &outptr, &outleft) == -1) {
+  if (iconv(cd, (const char**)&input, &length, &outptr, &outleft) == -1) {
     int used;
     switch (errno) {
     case E2BIG:
