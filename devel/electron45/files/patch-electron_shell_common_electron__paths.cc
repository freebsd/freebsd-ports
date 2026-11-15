--- electron/shell/common/electron_paths.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/common/electron_paths.cc
@@ -14,7 +14,7 @@
 #include "shell/common/platform_util.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -64,7 +64,7 @@ bool ElectronPathProvider(int key, base::FilePath* res
       create_dir = true;
       break;
     }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case DIR_APP_DATA: {
       auto env = base::Environment::Create();
       cur = base::nix::GetXDGDirectory(
