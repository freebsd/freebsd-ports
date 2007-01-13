--- lashd/main.c.orig	Sat Jan 13 15:15:39 2007
+++ lashd/main.c	Sat Jan 13 15:20:07 2007
@@ -24,7 +24,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
-#include <mcheck.h>
 #include <limits.h>
 
 #include <jack/jack.h>
@@ -96,7 +95,7 @@
 		{0, 0, 0, 0}
 	};
 	char *default_dir = NULL;
-	sighandler_t sigh;
+	sig_t sigh;
 
 #ifdef LASH_DEBUG
 	mtrace();
