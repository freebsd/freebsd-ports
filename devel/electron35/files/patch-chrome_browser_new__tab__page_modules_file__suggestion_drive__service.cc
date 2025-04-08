--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -35,7 +35,7 @@ namespace {
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
