--- libjack/driver.c.orig	Thu Dec 11 00:50:40 2003
+++ libjack/driver.c	Tue Mar  9 19:52:04 2004
@@ -24,6 +24,7 @@
 #include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <errno.h>
 
@@ -105,6 +106,11 @@
                 return -1;
         }
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif        
+#if (defined(__APPLE__) && defined(__POWERPC__)) || (__FreeBSD_version < 501000)
+#else
         if (mlockall (MCL_CURRENT | MCL_FUTURE) != 0) {
 		jack_error ("cannot lock down memory for RT thread (%s)",
 			    strerror (errno));
@@ -112,7 +118,7 @@
 		return -1;
 #endif /* ENSURE_MLOCK */
         }
-
+#endif
         return 0;
 }
 
