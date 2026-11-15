--- chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/new_tab_page/modules/file_suggestion/drive_service.cc
@@ -39,7 +39,7 @@ namespace {
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kPlatform[] = "WINDOWS";
