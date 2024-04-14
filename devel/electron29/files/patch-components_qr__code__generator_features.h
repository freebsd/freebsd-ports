--- components/qr_code_generator/features.h.orig	2024-02-21 00:20:42 UTC
+++ components/qr_code_generator/features.h
@@ -26,7 +26,11 @@ inline bool IsRustyQrCodeGeneratorFeatureEnabled() {
 // See https://crbug.com/1431991 for more details about the feature and the
 // Rust QR Code Generator project.
 inline bool IsRustyQrCodeGeneratorFeatureEnabled() {
+#ifdef notyet
   return base::FeatureList::IsEnabled(kRustyQrCodeGeneratorFeature);
+#else
+  return false;
+#endif
 }
 
 }  // namespace qr_code_generator
