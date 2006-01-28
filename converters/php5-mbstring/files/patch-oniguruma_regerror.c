--- oniguruma/regerror.c.orig	Sat Jan 28 09:53:54 2006
+++ oniguruma/regerror.c	Sat Jan 28 09:56:58 2006
@@ -27,6 +27,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "regint.h"
 #include <stdio.h> /* for vsnprintf() */
 
