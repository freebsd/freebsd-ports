--- ipelib/ipeplatform.cpp.orig	2019-03-09 12:21:05 UTC
+++ ipelib/ipeplatform.cpp
@@ -48,7 +48,10 @@
 #include <sys/param.h>
 #include <sys/errno.h>
 #endif
-
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <xlocale.h>
+#include <sys/errno.h>
+#endif
 #include <cstdlib>
 #include <sys/types.h>
 #include <sys/stat.h>
