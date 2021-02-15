--- src/common/provider/ScaledSizeProvider.h.orig	2021-02-15 12:17:05 UTC
+++ src/common/provider/ScaledSizeProvider.h
@@ -22,11 +22,6 @@
 
 #include <QSize>
 
-#if defined(__linux__)
-#include <QApplication>
-#include <QScreen>
-#endif
-
 #include "src/common/platform/PlatformChecker.h"
 
 class ScaledSizeProvider
