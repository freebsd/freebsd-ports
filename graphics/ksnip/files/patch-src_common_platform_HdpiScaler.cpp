--- src/common/platform/HdpiScaler.cpp.orig	2020-12-30 20:58:35 UTC
+++ src/common/platform/HdpiScaler.cpp
@@ -74,7 +74,7 @@ qreal HdpiScaler::scaleFactor() const
 
 #endif
 	
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(_WIN32)
 	return desktopWidget->devicePixelRatioF();
 #endif
 }
