--- inject.c.orig	Sat Jul 16 18:25:27 2005
+++ inject.c	Sat Jul 16 18:25:47 2005
@@ -23,6 +23,7 @@
 #include "roteprivate.h"
 #include "inject_csi.h"
 #include <string.h>
+#include <stdbool.h>
 
 static void cursor_line_down(RoteTerm *rt) {
    int i;
