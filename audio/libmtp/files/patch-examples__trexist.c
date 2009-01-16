--- ./examples/trexist.c.orig	2007-11-11 03:06:28.000000000 +0300
+++ ./examples/trexist.c	2009-01-14 01:12:55.000000000 +0300
@@ -20,6 +20,8 @@
  * Boston, MA 02111-1307, USA.
  */
 #include "common.h"
+#include <stdlib.h>
+#include <limits.h>
 
 static void usage (void)
 {
