--- chrome/browser/search/drive/drive_service.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/search/drive/drive_service.cc
@@ -19,6 +19,8 @@ namespace {
 constexpr char kDriveScope[] = "https://www.googleapis.com/auth/drive.readonly";
 #if OS_LINUX
 constexpr char kPlatform[] = "LINUX";
+#elif OS_FREEBSD
+constexpr char kPlatform[] = "FREEBSD";
 #elif OS_WIN
 constexpr char kPlatform[] = "WINDOWS";
 #elif OS_MAC
