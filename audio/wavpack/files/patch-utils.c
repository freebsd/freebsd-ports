--- utils.c.orig	Sun Mar 20 08:16:38 2005
+++ utils.c	Mon Jul 11 13:25:37 2005
@@ -613,6 +613,7 @@
     MultiByteToWideChar (CP_ACP, 0, string, -1, temp, max_chars + 1);
     WideCharToUTF8 (temp, (uchar *) string, len);
 #else
+    iconv_t converter;
     char *temp = malloc (len);
 //  memset(temp, 0, len);
     char *outp = temp;
@@ -624,7 +625,7 @@
 
     memset(temp, 0, len);
     old_locale = setlocale (LC_CTYPE, "");
-    iconv_t converter = iconv_open ("UTF-8", "");
+    converter = iconv_open ("UTF-8", "");
     err = iconv (converter, &inp, &insize, &outp, &outsize);
     iconv_close (converter);
     setlocale (LC_CTYPE, old_locale);
