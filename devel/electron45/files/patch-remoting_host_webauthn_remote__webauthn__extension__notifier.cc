--- remoting/host/webauthn/remote_webauthn_extension_notifier.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/webauthn/remote_webauthn_extension_notifier.cc
@@ -27,7 +27,7 @@
 #include "base/task/thread_pool.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "base/strings/string_util.h"
@@ -114,18 +114,18 @@ RemoteWebAuthnExtensionNotifier::GetRemoteStateChangeC
 // directory only exists if the corresponding Chrome version is installed.
 RemoteWebAuthnExtensionNotifier::RemoteStateChangeContext
 RemoteWebAuthnExtensionNotifier::GetRemoteStateChangeContext() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   constexpr base::FilePath::CharType kStateChangeDirName[] =
       FILE_PATH_LITERAL("WebAuthenticationProxyRemoteSessionStateChange");
 #endif
 
   RemoteWebAuthnExtensionNotifier::RemoteStateChangeContext context;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::vector<base::FilePath>& dirs = context.dirs;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // See: chrome/common/chrome_paths_linux.cc
   auto env = base::Environment::Create();
   base::FilePath base_path;
