--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -38,7 +38,7 @@ namespace {
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
