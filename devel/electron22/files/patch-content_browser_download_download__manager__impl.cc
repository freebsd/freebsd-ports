--- content/browser/download/download_manager_impl.cc.orig	2022-10-24 13:33:33 UTC
+++ content/browser/download/download_manager_impl.cc
@@ -92,7 +92,7 @@
 #include "third_party/blink/public/common/storage_key/storage_key.h"
 #include "url/origin.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -219,7 +219,7 @@ class DownloadItemFactoryImpl : public download::Downl
   }
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::FilePath GetTemporaryDownloadDirectory() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   return base::nix::GetXDGDirectory(env.get(), "XDG_DATA_HOME", ".local/share");
@@ -655,7 +655,7 @@ bool DownloadManagerImpl::InterceptDownload(
 
 base::FilePath DownloadManagerImpl::GetDefaultDownloadDirectory() {
   base::FilePath default_download_directory;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(thomasanderson,crbug.com/784010): Remove this when all Linux
   // distros with versions of GTK lower than 3.14.7 are no longer
   // supported.  This should happen when support for Ubuntu Trusty and
