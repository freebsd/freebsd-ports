--- engine/i386/cpu.c.orig	2003-10-05 09:50:36.000000000 +0900
+++ engine/i386/cpu.c	2011-08-02 21:40:31.000000000 +0900
@@ -12,6 +12,7 @@
 	#include <pthread.h>
 	#include <semaphore.h>
 	#if defined(__FreeBSD__)
+		#include <sys/types.h>
 		#include <sys/sysctl.h>
 	#endif
 #endif
