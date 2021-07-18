--- src/Common/MemoryStatisticsOS.h.orig	2021-03-19 11:39:14 UTC
+++ src/Common/MemoryStatisticsOS.h
@@ -1,5 +1,4 @@
 #pragma once
-#if defined(OS_LINUX)
 #include <cstdint>
 
 
@@ -35,9 +34,12 @@ class MemoryStatisticsOS (public)
     Data get() const;
 
 private:
+#ifdef OS_FREEBSD
+    struct procstat * pstat;
+#else
     int fd;
+#endif
 };
 
 }
 
-#endif
