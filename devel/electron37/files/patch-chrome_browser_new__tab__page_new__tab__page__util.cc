--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -29,7 +29,7 @@ bool IsOsSupportedForDrive() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
