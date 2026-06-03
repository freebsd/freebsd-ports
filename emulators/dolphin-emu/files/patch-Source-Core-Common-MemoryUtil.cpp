--- Source/Core/Common/MemoryUtil.cpp.orig	2026-03-11 23:36:49 UTC
+++ Source/Core/Common/MemoryUtil.cpp
@@ -20,6 +20,7 @@
 #include <pthread.h>
 #endif
 #if defined __APPLE__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #elif defined __HAIKU__
 #include <OS.h>
