--- tuxpuck.c.orig	Thu Apr 25 23:24:18 2002
+++ tuxpuck.c	Thu Apr 25 23:24:39 2002
@@ -40,7 +40,7 @@
 #endif
 
 /* externals */
-extern time_t time(time_t *);
+#include <time.h>
 extern void run_intro(void);
 extern AIPlayer *tux_create(Pad *, Puck *);
 extern AIPlayer *arcana_create(Pad *, Puck *);
