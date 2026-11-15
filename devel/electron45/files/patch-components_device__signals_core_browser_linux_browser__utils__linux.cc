--- components/device_signals/core/browser/linux/browser_utils_linux.cc.orig	2026-10-19 21:50:55 UTC
+++ components/device_signals/core/browser/linux/browser_utils_linux.cc
@@ -81,7 +81,7 @@ SettingValue GetOSFirewall() {
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char** GetUfwConfigPath() {
   static const char* path = "/etc/ufw/ufw.conf";
   return &path;
