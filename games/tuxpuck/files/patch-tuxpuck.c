--- tuxpuck.c.orig	2002-11-08 10:50:29 UTC
+++ tuxpuck.c
@@ -17,7 +17,7 @@
 #endif
 
 /* externals */
-extern time_t time(time_t *);
+#include <time.h>
 extern void run_intro(void);
 extern AIPlayer *tux_create(Pad *, Puck *);
 extern AIPlayer *arcana_create(Pad *, Puck *);
