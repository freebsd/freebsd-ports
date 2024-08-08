--- remoting/host/webauthn/remote_webauthn_extension_notifier.cc.orig	2023-02-01 18:43:24 UTC
+++ remoting/host/webauthn/remote_webauthn_extension_notifier.cc
@@ -24,7 +24,7 @@
 #include "base/task/thread_pool.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "base/strings/string_util.h"
@@ -69,14 +69,14 @@ static constexpr char kExtensionWakeupFileContent[] = 
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
   // See: chrome/common/chrome_paths_linux.cc
   auto env = base::Environment::Create();
   base::FilePath base_path;
