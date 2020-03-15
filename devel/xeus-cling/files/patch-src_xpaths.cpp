--- src/xpaths.cpp.orig	2019-12-23 15:12:48 UTC
+++ src/xpaths.cpp
@@ -24,6 +24,10 @@
 #    undef NOMINMAX
 #  endif
 #endif
+#ifdef __FreeBSD__
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+#endif
 #ifdef __APPLE__
 #  include <cstdint>
 #  include <mach-o/dyld.h>
@@ -69,7 +73,7 @@ namespace xcpp
         }
 #elif defined (__FreeBSD__)
         int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
-        if (sysctl(mib, 4, buffer, sizeof(buffer), NULL, 0) != -1)
+        if (sysctl(mib, 4, nullptr, nullptr, buffer, sizeof(buffer)) != -1)
         {
             path = buffer;
         }
