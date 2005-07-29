--- vcl/unx/source/app/saldata.cxx.orig	Sun Jun  2 22:07:34 2002
+++ vcl/unx/source/app/saldata.cxx	Sun Jun  2 22:08:22 2002
@@ -78,6 +78,11 @@
 #ifdef AIX
 #include <strings.h>
 #endif
+#ifdef FREEBSD
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+#endif
 
 #ifndef _VOS_MUTEX_HXX
 #include <vos/mutex.hxx>
