--- fribidi.c.orig	Thu Apr 20 20:32:11 2006
+++ fribidi.c	Thu Apr 20 20:32:20 2006
@@ -32,7 +32,7 @@
 #include <fribidi/fribidi.h>
 
 /* The fribidi guys dont believe in BC */
-/*#ifndef FRIBIDI_CHARSET_UTF8
+#ifndef FRIBIDI_CHARSET_UTF8
 #define FRIBIDI_CHARSET_UTF8                FRIBIDI_CHAR_SET_UTF8
 #define FRIBIDI_CHARSET_ISO8859_6           FRIBIDI_CHAR_SET_ISO8859_6
 #define FRIBIDI_CHARSET_ISO8859_8           FRIBIDI_CHAR_SET_ISO8859_8
@@ -40,7 +40,7 @@
 #define FRIBIDI_CHARSET_CP1256              FRIBIDI_CHAR_SET_CP1256
 #define FRIBIDI_CHARSET_ISIRI_3342          FRIBIDI_CHAR_SET_ISIRI_3342
 #define FRIBIDI_CHARSET_CAP_RTL             FRIBIDI_CHAR_SET_CAP_RTL
-#endif*/
+#endif
 
 function_entry fribidi_functions[] = {
 	PHP_FE(fribidi_log2vis,	     NULL)
