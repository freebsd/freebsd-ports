--- src/command.c.orig	Mon Feb  7 22:20:41 2000
+++ src/command.c	Mon Feb  7 22:22:16 2000
@@ -40,6 +40,8 @@
 #include "config.h"
 #include "feature.h"
 
+#undef HAVE_SAVED_UIDS
+
 /* System Headers */
 #include <stdio.h>
 #include <stdlib.h>
@@ -1560,6 +1562,9 @@
 # endif
 # if VTIME != VEOL
   tio->c_cc[VTIME] = 0;
+# endif
+# ifdef VSTATUS
+    tio->c_cc[VSTATUS] = CSTATUS;
 # endif
 
   /* input modes */
