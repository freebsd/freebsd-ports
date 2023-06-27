--- chrome/updater/app/app_uninstall.cc.orig	2023-05-25 00:41:49 UTC
+++ chrome/updater/app/app_uninstall.cc
@@ -39,7 +39,7 @@
 #include "chrome/updater/posix/setup.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1431487): Remove these includes after investigation.
 #include "base/ranges/algorithm.h"
 #include "url/gurl.h"
@@ -141,7 +141,7 @@ void AppUninstall::UninstallAll(int reason) {
     uninstall_data.version = base::Version(kUpdaterVersion);
   }
 // TODO(crbug.com/1431487): Remove this code after investigation.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(base::ranges::none_of(config_->PingUrl(), [](const GURL& url) {
     return url.DomainIs("update.googleapis.com");
   })) << "Attempted to send an uninstall ping to non-local server";
