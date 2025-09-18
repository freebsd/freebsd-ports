--- remoting/host/crash/crash_file_uploader.cc.orig	2024-08-14 20:55:09 UTC
+++ remoting/host/crash/crash_file_uploader.cc
@@ -44,7 +44,7 @@ constexpr char kProductNameValue[] = "Chromoting";
 
 #if BUILDFLAG(IS_WIN)
 constexpr char kProductNameValue[] = "Chromoting";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductNameValue[] = "Chromoting_Linux";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kProductNameValue[] = "Chromoting_Mac";
