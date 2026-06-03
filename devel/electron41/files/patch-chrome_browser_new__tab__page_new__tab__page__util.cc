--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -52,7 +52,7 @@ bool IsOsSupportedForDrive() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
