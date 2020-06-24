--- src/common/helper/FileUrlHelper.cpp.orig	2020-06-24 10:57:05 UTC
+++ src/common/helper/FileUrlHelper.cpp
@@ -26,7 +26,7 @@ QString FileUrlHelper::parse(const QString &text)
 	return url.remove(QStringLiteral("file://"));
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	return url.remove(QStringLiteral("file://"));
 #endif
 
