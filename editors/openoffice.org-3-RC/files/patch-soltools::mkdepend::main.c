--- ../soltools/mkdepend/main.c.orig	Mon Mar 11 20:09:35 2002
+++ ../soltools/mkdepend/main.c	Mon Mar 11 17:25:55 2002
@@ -27,6 +27,11 @@
 
 */
 
+#ifdef FREEBSD
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
+
 #include "def.h"
 #ifdef hpux
 #define sigvec sigvector
