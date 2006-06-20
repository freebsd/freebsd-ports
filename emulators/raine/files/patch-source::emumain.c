--- source/emumain.c.orig	Wed Aug 17 13:14:36 2005
+++ source/emumain.c	Thu Nov 17 18:04:37 2005
@@ -9,1 +9,1 @@
 #include <winalleg.h>
 #endif
 
+#ifdef RAINE_UNIX
+#include <sys/time.h>
+#endif
+
 #include "raine.h"              // General defines and stuff
 #include "gui.h"                // Interface stuff
 #include "sasound.h"            // Sound Sample stuff
