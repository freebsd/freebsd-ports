--- sys_custom.h.orig	Mon Jul 17 21:02:18 2000
+++ sys_custom.h	Mon Jul 17 21:02:41 2000
@@ -7,7 +7,9 @@
 #ifndef _sys_custom_
 #define _sys_custom_
 
+#ifndef SCOREFILE
 #define SCOREFILE "/usr/games/lib/trojka.scores"
+#endif
 
 #define UMASK 0666    			/* creation mask for hiscorefile */ 
 
