--- gplot.c.orig	Thu Oct 31 06:33:47 1991
+++ gplot.c	Sat Jun 16 02:01:54 2007
@@ -4,6 +4,8 @@
    considered callable by other programs (inclusion of graphics with text) 
 */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "defs.h"
 #define max_str 128
 #define  version_str "4.3b2"
