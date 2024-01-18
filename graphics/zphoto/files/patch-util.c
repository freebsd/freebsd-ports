--- util.c.orig	2004-07-20 16:48:11 UTC
+++ util.c
@@ -389,7 +389,7 @@ zphoto_get_image_suffixes (void)
 zphoto_get_image_suffixes (void)
 {
     static char *empty[] = { NULL };
-    static char *suffixes[] = { "jpg", "png", "gif", "bmp", NULL };
+    static char *suffixes[] = { "jpeg", "jpg", "png", "gif", "bmp", NULL };
 
     if (zphoto_support_image_p()) {
         return suffixes;
