
$FreeBSD$

--- wavpack.c.orig
+++ wavpack.c
@@ -1604,6 +1604,7 @@
     MultiByteToWideChar (CP_ACP, 0, string, -1, temp, max_chars + 1);
     WideCharToUTF8 (temp, (uchar *) string, len);
 #else
+    iconv_t converter;
     char *temp = malloc (len);
     char *outp = temp;
     char *inp = string;
@@ -1614,7 +1615,7 @@
 
     memset(temp, 0, len);
     old_locale = setlocale (LC_CTYPE, "");
-    iconv_t converter = iconv_open ("UTF-8", "");
+    converter = iconv_open ("UTF-8", "");
     err = iconv (converter, &inp, &insize, &outp, &outsize);
     iconv_close (converter);
     setlocale (LC_CTYPE, old_locale);
