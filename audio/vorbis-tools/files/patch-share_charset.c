
$FreeBSD$

--- share/charset.c.orig
+++ share/charset.c
@@ -27,6 +27,10 @@
  * 8-bit char, 16-bit short and 32-bit int.
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #ifndef HAVE_ICONV /* should be ifdef USE_CHARSET_CONVERT */
 
 #include <stdlib.h>
