--- remoting/host/config_file_watcher.cc.orig	2026-06-23 23:37:18 UTC
+++ remoting/host/config_file_watcher.cc
@@ -27,7 +27,7 @@ const base::FilePath::CharType kDefaultHostConfigFile[
 const base::FilePath::CharType kDefaultHostConfigFile[] =
     FILE_PATH_LITERAL("host.json");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kDefaultUnprivilegedConfigFileName[] =
     FILE_PATH_LITERAL("host_unprivileged.json");
 #endif
