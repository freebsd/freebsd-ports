--- ext/ming/mingc/swfbitmap.c.orig	2011-08-08 14:02:17.000000000 +0000
+++ ext/ming/mingc/swfbitmap.c	2011-08-08 14:02:53.000000000 +0000
@@ -58,7 +58,7 @@
     RAISE_NOF(filename);
 
   if(NIL_P(a)) {
-    len = RSTRING(f)->len;
+    len = RSTRING_LEN(f);
     if(len > 5) {
       ext = &filename[len - 5];
       if(strncmp(ext, ".jpeg", 5) == 0) {
