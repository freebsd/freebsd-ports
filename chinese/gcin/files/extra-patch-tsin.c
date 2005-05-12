--- tsin.c.orig	Thu May 12 04:08:09 2005
+++ tsin.c	Thu May 12 04:08:45 2005
@@ -1107,7 +1107,7 @@
 static gboolean pre_punctuation(KeySym xkey)
 {
   static char shift_punc[]="<>?:\"{}!";
-  static char chars[]="ï¼????ï¼???????";
+  static char chars[]="ï¼????ï¼???????";
 
   char *p;
 
