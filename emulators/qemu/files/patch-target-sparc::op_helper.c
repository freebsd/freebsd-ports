--- qemu/target-sparc/op_helper.c.orig	Mon Oct 11 02:46:24 2004
+++ qemu/target-sparc/op_helper.c	Thu Oct 28 23:28:57 2004
@@ -1,5 +1,4 @@
 #include <math.h>
-#include <fenv.h>
 #include "exec.h"
 
 #ifdef USE_INT_TO_FLOAT_HELPERS
