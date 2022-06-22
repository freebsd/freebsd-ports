--- remoting/host/remote_open_url/remote_open_url_util.cc.orig	2022-05-19 03:45:37 UTC
+++ remoting/host/remote_open_url/remote_open_url_util.cc
@@ -30,7 +30,7 @@ const wchar_t kRegisteredApplicationsKeyName[] =
 #endif  // defined (OS_WIN)
 
 bool IsRemoteOpenUrlSupported() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #elif BUILDFLAG(IS_WIN)
   // The modern default apps settings dialog is only available to Windows 8+.
