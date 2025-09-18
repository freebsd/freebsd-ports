--- services/shape_detection/shape_detection_service.cc.orig	2025-08-26 20:49:50 UTC
+++ services/shape_detection/shape_detection_service.cc
@@ -22,7 +22,7 @@
 #elif BUILDFLAG(IS_ANDROID)
 // No C++ code, barcode detection comes from Java.
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "services/shape_detection/barcode_detection_provider_chrome.h"
 #else
 #include "services/shape_detection/barcode_detection_provider_impl.h"
@@ -56,7 +56,7 @@ void ShapeDetectionService::BindBarcodeDetectionProvid
 #elif BUILDFLAG(IS_MAC)
   BarcodeDetectionProviderMac::Create(std::move(receiver));
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   BarcodeDetectionProviderChrome::Create(std::move(receiver));
 #else
   BarcodeDetectionProviderImpl::Create(std::move(receiver));
