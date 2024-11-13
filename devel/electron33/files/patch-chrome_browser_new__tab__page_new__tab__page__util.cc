--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2024-10-16 21:30:58 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -25,7 +25,7 @@ bool IsOsSupportedForDrive() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
