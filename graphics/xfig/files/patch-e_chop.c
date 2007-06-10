--- e_chop.c.orig	Tue Jul 26 09:56:28 2005
+++ e_chop.c
@@ -19,7 +19,9 @@
 /* >>>>>>>>>>>>>>>>>>> fixme -- don't forget undo ! <<<<<<<<<<<<<<<< */
 
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include "fig.h"
 #include "resources.h"
 #include "mode.h"
