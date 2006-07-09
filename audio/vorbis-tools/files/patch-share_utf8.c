
$FreeBSD$

--- share/utf8.c.orig
+++ share/utf8.c
@@ -21,6 +21,10 @@
  * Convert a string between UTF-8 and the locale's charset.
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #include <stdlib.h>
 #include <string.h>
 
