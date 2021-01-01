--- third_party/skia/src/core/SkCpu.cpp.orig	2019-12-12 12:48:52 UTC
+++ third_party/skia/src/core/SkCpu.cpp
@@ -76,6 +76,8 @@
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
+return 0;
+#if 0
         const uint32_t kHWCAP_CRC32   = (1<< 7),
                        kHWCAP_ASIMDHP = (1<<10);
 
@@ -112,6 +114,7 @@
             }
         }
         return features;
+#endif
     }
 
 #elif defined(SK_CPU_ARM32) && __has_include(<sys/auxv.h>) && \
