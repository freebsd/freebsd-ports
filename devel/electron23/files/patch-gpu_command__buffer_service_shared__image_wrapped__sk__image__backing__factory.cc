--- gpu/command_buffer/service/shared_image/wrapped_sk_image_backing_factory.cc.orig	2023-02-01 18:43:20 UTC
+++ gpu/command_buffer/service/shared_image/wrapped_sk_image_backing_factory.cc
@@ -216,7 +216,7 @@ class WrappedSkImage : public ClearTrackingSharedImage
                                                       : GrMipMapped::kNo;
     const std::string label = "WrappedSkImageBackingFactory_Initialize" +
                               CreateLabelForSharedImageUsage(usage());
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Initializing to bright green makes it obvious if the pixels are not
     // properly set before they are displayed (e.g. https://crbug.com/956555).
     // We don't do this on release builds because there is a slight overhead.
