--- ipelib/ipeplatform.cpp.orig	2019-05-02 09:29:29 UTC
+++ ipelib/ipeplatform.cpp
@@ -48,7 +48,11 @@
 #include <sys/param.h>
 #include <sys/errno.h>
 #endif
-
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <limits.h>
+#include <xlocale.h>
+#include <sys/errno.h>
+#endif
 #include <cstdlib>
 #include <sys/types.h>
 #include <sys/stat.h>
