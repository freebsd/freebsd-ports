--- src/line.c.orig	Sat May 10 00:11:53 2003
+++ src/line.c	Sat May 10 00:12:04 2003
@@ -4,11 +4,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#ifdef __FreeBSD__
-#include <machine/soundcard.h>
-#else
 #include <sys/soundcard.h>
-#endif
 
 #include <fcntl.h>
 #include <unistd.h>
