--- chrome/updater/configurator.cc.orig	2023-02-01 18:43:15 UTC
+++ chrome/updater/configurator.cc
@@ -57,7 +57,7 @@ Configurator::Configurator(scoped_refptr<UpdaterPrefs>
           base::MakeRefCounted<update_client::InProcessUnzipperFactory>()),
       patch_factory_(
           base::MakeRefCounted<update_client::InProcessPatcherFactory>()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux creating the NetworkFetcherFactory requires performing blocking IO
   // to load an external library. This should be done when the configurator is
   // created.
