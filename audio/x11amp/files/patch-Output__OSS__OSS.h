--- ./Output/OSS/OSS.h.orig	Sat Sep  7 18:38:05 2002
+++ ./Output/OSS/OSS.h	Sat Sep  7 18:38:13 2002
@@ -23,11 +23,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/time.h>
-#ifdef __FreeBSD__
-#include <machine/soundcard.h>
-#else
 #include <sys/soundcard.h>
-#endif
 
 #include <fcntl.h>
 #include <pthread.h>
