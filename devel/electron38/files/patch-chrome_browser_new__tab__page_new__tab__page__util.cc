--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -32,7 +32,7 @@ bool IsOsSupportedForDrive() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
