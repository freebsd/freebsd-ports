--- src/common/provider/ScaledSizeProvider.cpp.orig	2021-02-15 12:17:15 UTC
+++ src/common/provider/ScaledSizeProvider.cpp
@@ -19,6 +19,11 @@
 
 #include "ScaledSizeProvider.h"
 
+#if defined(UNIX_X11)
+#include <QApplication>
+#include <QScreen>
+#endif
+
 QSize ScaledSizeProvider::scaledSize(const QSize &size)
 {
 	return size * scaleFactor();
