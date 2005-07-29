--- soltools/mkdepend/main.c.orig	Mon Apr 15 15:55:43 2002
+++ soltools/mkdepend/main.c	Mon Apr 15 16:54:06 2002
@@ -27,6 +27,9 @@
 
 */
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include "def.h"
 #ifdef hpux
 #define sigvec sigvector
