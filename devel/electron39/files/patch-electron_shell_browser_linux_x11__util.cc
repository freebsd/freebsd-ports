--- electron/shell/browser/linux/x11_util.cc.orig	2026-03-18 13:26:09 UTC
+++ electron/shell/browser/linux/x11_util.cc
@@ -10,7 +10,7 @@ bool IsX11() {
 namespace x11_util {
 
 bool IsX11() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool is = ui::GetOzonePlatformId() == ui::kPlatformX11;
   return is;
 #else
@@ -19,7 +19,7 @@ bool IsWayland() {
 }
 
 bool IsWayland() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool is = ui::GetOzonePlatformId() == ui::kPlatformWayland;
   return is;
 #else
