--- mcop_mt/threads_posix.cc.orig	2009-01-12 11:45:39.000000000 +0100
+++ mcop_mt/threads_posix.cc	2009-01-12 11:46:13.000000000 +0100
@@ -27,6 +27,7 @@
 /* only compile this if we have libpthread available */
 #ifdef HAVE_LIBPTHREAD
 
+#include <signal.h>
 #include <gsl/gslconfig.h>
 
 #include <sys/types.h>
