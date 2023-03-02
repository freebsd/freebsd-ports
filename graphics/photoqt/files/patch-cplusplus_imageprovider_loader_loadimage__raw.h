Fix build with libraw >= 0.21.0

--- cplusplus/imageprovider/loader/loadimage_raw.h.orig	2023-03-02 16:52:09 UTC
+++ cplusplus/imageprovider/loader/loadimage_raw.h
@@ -56,7 +56,11 @@ class LoadImageRaw { (public)
         // Since we don't care about manipulating RAW images but only want to display
         // them, we can optimise for speed
         raw.imgdata.params.user_qual = 2;
+#if LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 21)
+        raw.imgdata.rawparams.use_rawspeed = 1;
+#else
         raw.imgdata.params.use_rawspeed = 1;
+#endif
         raw.imgdata.params.use_camera_wb = 1;
 
         // Open the RAW image
