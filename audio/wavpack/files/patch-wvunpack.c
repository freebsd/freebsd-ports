--- wvunpack.c.orig	Thu Apr  6 05:48:33 2006
+++ wvunpack.c	Mon May 15 03:42:14 2006
@@ -1040,6 +1040,8 @@
 static UTF8ToAnsi (char *string, int len)
 {
     int max_chars = strlen (string);
+
+    iconv_t converter;
 #if defined (WIN32)
     unsigned short *temp = malloc ((max_chars + 1) * 2);
     int act_chars = UTF8ToWideChar (string, temp);
@@ -1066,7 +1068,7 @@
 
     memset(temp, 0, len);
     old_locale = setlocale (LC_CTYPE, "");
-    iconv_t converter = iconv_open ("", "UTF-8");
+    converter = iconv_open ("", "UTF-8");
     err = iconv (converter, &inp, &insize, &outp, &outsize);
     iconv_close (converter);
     setlocale (LC_CTYPE, old_locale);
