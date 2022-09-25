--- stellarsolver/stellarsolver.cpp.orig	2022-07-29 16:11:55 UTC
+++ stellarsolver/stellarsolver.cpp
@@ -7,6 +7,9 @@
 */
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(_WIN32)
 #include "windows.h"
 #else //Linux
@@ -987,8 +990,12 @@ bool StellarSolver::getAvailableRAM(double &availableR
 //But from what I read, getting the Available RAM is inconsistent and buggy on many systems.
 bool StellarSolver::getAvailableRAM(double &availableRAM, double &totalRAM)
 {
-#if defined(Q_OS_OSX)
+#if defined(Q_OS_OSX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD)
+    int mib [] = { CTL_HW, HW_REALMEM };
+#else
     int mib [] = { CTL_HW, HW_MEMSIZE };
+#endif
     size_t length;
     length = sizeof(int64_t);
     int64_t RAMcheck;
