--- source/emumain.c.orig	Mon Jan 17 11:47:24 2005
+++ source/emumain.c	Mon Jan 17 11:49:36 2005
@@ -9,6 +9,10 @@
 #include <winalleg.h>
 #endif

+#ifdef RAINE_UNIX
+#include <sys/time.h>
+#endif
+
 #include "raine.h"              // General defines and stuff
 #include "gui.h"                // Interface stuff
 #include "sasound.h"            // Sound Sample stuff
