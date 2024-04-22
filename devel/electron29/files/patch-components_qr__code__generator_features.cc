--- components/qr_code_generator/features.cc.orig	2024-02-21 00:20:42 UTC
+++ components/qr_code_generator/features.cc
@@ -11,6 +11,10 @@ BASE_FEATURE(kRustyQrCodeGeneratorFeature,
 
 BASE_FEATURE(kRustyQrCodeGeneratorFeature,
              "RustyQrCodeGenerator",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_DISABLED_BY_DEFAULT);
+#else
              base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 }  // namespace qr_code_generator
