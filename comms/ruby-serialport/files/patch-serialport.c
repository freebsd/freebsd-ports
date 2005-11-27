--- serialport.c.orig	Sun Nov 27 10:28:52 2005
+++ serialport.c	Sun Nov 27 10:35:17 2005
@@ -20,6 +20,10 @@
 #include <ruby.h>    /* ruby inclusion */
 #include <rubyio.h>  /* ruby io inclusion */
 
+#if defined (freebsd)
+#include <sys/param.h>
+#endif
+
 struct modem_params {
   int data_rate;
   int data_bits;
@@ -569,9 +573,12 @@
 #if defined(linux) || defined(cygwin)
   "/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2", "/dev/ttyS3",
   "/dev/ttyS4", "/dev/ttyS5", "/dev/ttyS6", "/dev/ttyS7"
-#elif defined(freebsd) || defined(netbsd) || defined(openbsd)
+#elif (defined(freebsd) && __FreeBSD_version < 600006) || defined(netbsd) || defined(openbsd)
   "/dev/cuaa0", "/dev/cuaa1", "/dev/cuaa2", "/dev/cuaa3",
   "/dev/cuaa4", "/dev/cuaa5", "/dev/cuaa6", "/dev/cuaa7"
+#elif (defined(freebsd) && __FreeBSD_version >= 600006)
+  "/dev/cuad0", "/dev/cuad1", "/dev/cuad2", "/dev/cuad3",
+  "/dev/cuad4", "/dev/cuad5", "/dev/cuad6", "/dev/cuad7"
 #elif defined(solaris)
   "/dev/ttya", "/dev/ttyb", "/dev/ttyc", "/dev/ttyd",
   "/dev/ttye", "/dev/ttyf", "/dev/ttyg", "/dev/ttyh"
