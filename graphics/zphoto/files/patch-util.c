--- util.c.orig	2010-12-04 00:36:16.000000000 +0900
+++ util.c	2010-12-04 00:36:52.000000000 +0900
@@ -389,7 +389,7 @@
 zphoto_get_image_suffixes (void)
 {
     static char *empty[] = { NULL };
-    static char *suffixes[] = { "jpg", "png", "gif", "bmp", NULL };
+    static char *suffixes[] = { "jpeg", "jpg", "png", "gif", "bmp", NULL };
 
     if (zphoto_support_image_p()) {
         return suffixes;
