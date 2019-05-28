--- third_party/crashpad/crashpad/util/misc/metrics.cc.orig	2019-03-15 06:38:19 UTC
+++ third_party/crashpad/crashpad/util/misc/metrics.cc
@@ -24,7 +24,7 @@
 #define METRICS_OS_NAME "Win"
 #elif defined(OS_ANDROID)
 #define METRICS_OS_NAME "Android"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define METRICS_OS_NAME "Linux"
 #elif defined(OS_FUCHSIA)
 #define METRICS_OS_NAME "Fuchsia"
