--- libjack/client.c.orig	Sun Jan 11 20:07:14 2004
+++ libjack/client.c	Tue Mar  9 20:19:15 2004
@@ -26,20 +26,23 @@
 #else
     #include <sys/poll.h>
 #endif
-
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <pthread.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <sys/types.h>
+
 #include <sys/ipc.h>
 #include <sys/mman.h>
 
 #include <stdarg.h>
 #include <stdio.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <regex.h>
+#include <string.h>
 
 #include <config.h>
 
@@ -1152,8 +1155,12 @@
 				    "thread (%s)", strerror (errno));
 			return -1;
 		}
-                
-#if defined(__APPLE__) && defined(__POWERPC__) 
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif                
+#if defined(__APPLE__) && defined(__POWERPC__) || (__FreeBSD_version < 501000)
+
                 // To be implemented
 #else
                 if (mlockall (MCL_CURRENT | MCL_FUTURE) != 0) {
@@ -1307,8 +1314,11 @@
 	 * pages are actually mapped (more important for mlockall(2)
 	 * usage in jack_start_thread())
 	 */
-         
-#if defined(__APPLE__) && defined(__POWERPC__)
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif        
+#if (defined(__APPLE__) && defined(__POWERPC__)) || (__FreeBSD_version < 501000)
 /* a bigger stack makes the application crash... */
 #define BIG_ENOUGH_STACK 10000
 #else
