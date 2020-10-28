--- modules/javafx.web/src/main/native/Source/WTF/wtf/RAMSize.cpp.orig	2020-07-17 12:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/RAMSize.cpp
@@ -35,6 +35,10 @@
 #if OS(LINUX)
 #include <sys/sysinfo.h>
 #endif // OS(LINUX)
+#if OS(FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #else
 #include <bmalloc/bmalloc.h>
 #endif
@@ -59,6 +63,14 @@ static size_t computeRAMSize()
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif OS(FREEBSD)
+    size_t physmem, len;
+    int mib[2] = { CTL_HW, HW_PHYSMEM };
+    if (sysctl(mib, 2, &physmem, &len, NULL, 0) == 0
+        && len == sizeof(physmem))
+        return physmem;
+    else
+        return 512 * MB; // guess
 #else
 #error "Missing a platform specific way of determining the available RAM"
 #endif // OS(LINUX)
