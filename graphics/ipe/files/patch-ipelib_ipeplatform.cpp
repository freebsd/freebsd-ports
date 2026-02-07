--- ipelib/ipeplatform.cpp.orig	2020-12-24 12:20:13 UTC
+++ ipelib/ipeplatform.cpp
@@ -49,6 +49,11 @@
 #include <sys/param.h>
 #include <sys/errno.h>
 #endif
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <limits.h>
+#include <xlocale.h>
+#include <sys/errno.h>
+#endif
 
 #ifdef IPE_GSL
 #include <gsl/gsl_errno.h>
