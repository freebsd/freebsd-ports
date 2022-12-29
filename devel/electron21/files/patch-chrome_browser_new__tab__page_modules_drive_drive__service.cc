--- chrome/browser/new_tab_page/modules/drive/drive_service.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/new_tab_page/modules/drive/drive_service.cc
@@ -28,7 +28,7 @@
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)   
 constexpr char kPlatform[] = "LINUX";
 #elif OS_WIN
 constexpr char kPlatform[] = "WINDOWS";
