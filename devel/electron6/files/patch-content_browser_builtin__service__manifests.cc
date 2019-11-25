--- content/browser/builtin_service_manifests.cc.orig	2019-09-10 11:14:00 UTC
+++ content/browser/builtin_service_manifests.cc
@@ -33,7 +33,7 @@
 #include "services/video_capture/public/cpp/manifest.h"
 #include "services/viz/public/cpp/manifest.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/manifest.h"  // nogncheck
 #endif
 
@@ -99,7 +99,7 @@ const std::vector<service_manager::Manifest>& GetBuilt
                   : service_manager::Manifest::ExecutionMode::
                         kInProcessBuiltin),
           viz::GetManifest(),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
           font_service::GetManifest(),
 #endif
 #if defined(OS_CHROMEOS)
