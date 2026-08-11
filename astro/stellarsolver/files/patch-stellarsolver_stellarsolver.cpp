--- stellarsolver/stellarsolver.cpp.orig	2026-06-24 17:39:22 UTC
+++ stellarsolver/stellarsolver.cpp
@@ -9,6 +9,9 @@
 #include <QSettings>
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(_WIN32)
 #include "windows.h"
 #else //Linux
@@ -1020,6 +1023,11 @@ QStringList StellarSolver::getDefaultIndexFolderPaths(
     addPathToListIfExists(&indexFilePaths, QDir::homePath() + "/Library/Application Support/Astrometry");
     //Homebrew location
     addPathToListIfExists(&indexFilePaths, "/usr/local/share/astrometry");
+#elif defined(Q_OS_FREEBSD)
+    //FreeBSD Default Location
+    addPathToListIfExists(&indexFilePaths, "/usr/local/share/astrometry/");
+    //FreeBSD Local KStars Location
+    addPathToListIfExists(&indexFilePaths, QDir::homePath() + "/.local/share/kstars/astrometry/");
 #elif defined(Q_OS_LINUX)
     //Linux Default Location
     addPathToListIfExists(&indexFilePaths, "/usr/share/astrometry/");
@@ -1044,8 +1052,12 @@ bool StellarSolver::getAvailableRAM(double &availableR
 //But from what I read, getting the Available RAM is inconsistent and buggy on many systems.
 bool StellarSolver::getAvailableRAM(double &availableRAM, double &totalRAM)
 {
-#if defined(Q_OS_MACOS)
+#if defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD)
+    int mib [] = { CTL_HW, HW_REALMEM };
+#else
     int mib [] = { CTL_HW, HW_MEMSIZE };
+#endif
     size_t length;
     length = sizeof(int64_t);
     int64_t RAMcheck;
