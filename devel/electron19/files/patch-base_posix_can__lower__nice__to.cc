--- base/posix/can_lower_nice_to.cc.orig	2022-05-19 03:45:15 UTC
+++ base/posix/can_lower_nice_to.cc
@@ -11,8 +11,12 @@
 
 #include "build/build_config.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/param.h>
+#endif
+
 // Not defined on AIX by default.
-#if BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 #if defined(RLIMIT_NICE)
 #error Assumption about OS_AIX is incorrect
 #endif
