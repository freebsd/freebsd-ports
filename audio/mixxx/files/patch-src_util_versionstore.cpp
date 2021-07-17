--- src/util/versionstore.cpp.orig	2021-07-17 15:58:25 UTC
+++ src/util/versionstore.cpp
@@ -77,6 +77,8 @@ QString VersionStore::platform() {
     QString base = QStringLiteral("Linux");
 #elif defined(__WINDOWS__)
     QString base = QStringLiteral("Windows");
+#elif defined(__FreeBSD__)
+    QString base = QStringLiteral("FreeBSD");
 #else
     QString base = QStringLiteral("Unknown OS");
 #endif
