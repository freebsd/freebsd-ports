--- ./src/interface.c.orig	Sat May 10 00:13:43 2003
+++ ./src/interface.c	Sat May 10 00:13:48 2003
@@ -5,11 +5,7 @@
 #include <menu.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
-#include <machine/soundcard.h>
-#else
 #include <sys/soundcard.h>
-#endif
 
 #include <stdlib.h>
 
