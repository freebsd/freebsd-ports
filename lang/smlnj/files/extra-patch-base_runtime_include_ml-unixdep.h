--- base/runtime/include/ml-unixdep.h.orig	2012-08-02 20:03:33.000000000 +0200
+++ base/runtime/include/ml-unixdep.h	2013-06-18 13:16:20.292993889 +0200
@@ -371,6 +371,15 @@
 #  define __EXTENSIONS__
 #endif
 
+#if defined(OPSYS_FREEBSD)
+#  if defined(INCLUDE_FREEBSD_I386__TYPES)
+#    include <sys/cdefs.h>
+#    include INCLUDE_FREEBSD_I386__TYPES
+#  endif
+#  if defined(INCLUDE_FREEBSD_I386_SIGNAL)
+#    include INCLUDE_FREEBSD_I386_SIGNAL
+#  endif
+#endif
 #include INCLUDE_TYPES_H
 #include <unistd.h>
 #include <string.h>
