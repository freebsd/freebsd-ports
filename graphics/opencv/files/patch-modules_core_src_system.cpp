- workaround for https://github.com/opencv/opencv/issues/25527

--- modules/core/src/system.cpp.orig	2024-05-02 16:10:07 UTC
+++ modules/core/src/system.cpp
@@ -566,6 +566,7 @@ struct HWFeatures
     #ifdef __aarch64__
         have[CV_CPU_NEON] = true;
         have[CV_CPU_FP16] = true;
+#if 0 // disable until https://github.com/opencv/opencv/issues/25527 is fixed
         int cpufile = open("/proc/self/auxv", O_RDONLY);
 
         if (cpufile >= 0)
@@ -589,6 +590,7 @@ struct HWFeatures
 
             close(cpufile);
         }
+#endif
     #elif defined __arm__ && defined __ANDROID__
       #if defined HAVE_CPUFEATURES
         CV_LOG_INFO(NULL, "calling android_getCpuFeatures() ...");
