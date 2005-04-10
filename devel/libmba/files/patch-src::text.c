--- src/text.c.orig	Fri Feb 13 22:52:52 2004
+++ src/text.c	Sun Apr 10 22:25:00 2005
@@ -22,6 +22,8 @@
  * OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#include <sys/types.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <stddef.h>
