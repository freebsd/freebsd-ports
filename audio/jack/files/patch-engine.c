--- jackd/engine.c.orig	Sun Jan 11 20:07:13 2004
+++ jackd/engine.c	Tue Mar  9 19:43:47 2004
@@ -36,7 +36,9 @@
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdarg.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <dirent.h>
 #include <sys/ipc.h>
 #include <signal.h>
@@ -2119,8 +2124,10 @@
 			    strerror (errno));
 		return -1;
 	}
-        
-#if defined(__APPLE__) && defined(__POWERPC__) 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif        
+#if (defined(__APPLE__) && defined(__POWERPC__)) || (__FreeBSD_version < 501000)
         // To be implemented
 #else
         if (mlockall (MCL_CURRENT | MCL_FUTURE) != 0) {
