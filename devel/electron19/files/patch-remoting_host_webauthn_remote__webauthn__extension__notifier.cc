--- remoting/host/webauthn/remote_webauthn_extension_notifier.cc.orig	2022-05-25 04:01:06 UTC
+++ remoting/host/webauthn/remote_webauthn_extension_notifier.cc
@@ -49,14 +49,14 @@ namespace {
 // Caller should check if the directory exists before writing files to it. A
 // directory only exists if the corresponding Chrome version is installed.
 std::vector<base::FilePath> GetRemoteStateChangeDirPaths() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   constexpr base::FilePath::CharType kStateChangeDirName[] =
       FILE_PATH_LITERAL("WebAuthenticationProxyRemoteSessionStateChange");
 #endif
 
   std::vector<base::FilePath> dirs;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath base_path;
   if (!base::PathService::Get(base::DIR_HOME, &base_path)) {
     LOG(ERROR) << "Failed to get local app data dir";
