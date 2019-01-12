--- ipelib/ipeplatform.cpp.orig	2019-01-12 09:37:35 UTC
+++ ipelib/ipeplatform.cpp
@@ -44,7 +44,9 @@
 #include <mach-o/dyld.h>
 #include <xlocale.h>
 #endif
-
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <xlocale.h>
+#endif
 #include <cstdlib>
 #include <sys/types.h>
 #include <sys/stat.h>
