--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -37,7 +37,7 @@ namespace {
 #include "services/network/public/cpp/resource_request.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
