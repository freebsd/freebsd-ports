--- chrome/updater/ipc/ipc_names.h.orig	2023-02-01 18:43:15 UTC
+++ chrome/updater/ipc/ipc_names.h
@@ -13,7 +13,7 @@ namespace updater {
 mojo::NamedPlatformChannel::ServerName GetUpdateServiceInternalServerName(
     UpdaterScope scope);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 mojo::NamedPlatformChannel::ServerName GetUpdateServiceServerName(
     UpdaterScope scope);
 #endif  // BUILDFLAG(IS_LINUX)
