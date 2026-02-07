--- rote.c.orig	Wed Oct  6 09:18:49 2004
+++ rote.c	Sat Jul 16 18:28:22 2005
@@ -21,10 +21,15 @@
 
 #include "rote.h"
 #include "roteprivate.h"
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #include <stdlib.h>
-#include <pty.h>
 #include <stdio.h>
 #include <string.h>
+#include <stdbool.h>
+#include <sys/time.h>
 
 RoteTerm *rote_vt_create(int rows, int cols) {
    RoteTerm *rt;
@@ -53,7 +58,7 @@
    }
    
    /* allocate dirtiness array */
-   rt->line_dirty = (bool*) malloc(sizeof(bool) * rt->rows);
+   rt->line_dirty = malloc(sizeof(bool) * rt->rows);
 
    /* initialization of other public fields */
    rt->crow = rt->ccol = 0;
