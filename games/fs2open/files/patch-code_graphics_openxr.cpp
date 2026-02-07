--- code/graphics/openxr.cpp.orig	2025-11-04 13:12:38 UTC
+++ code/graphics/openxr.cpp
@@ -9,7 +9,7 @@ std::unique_ptr<star[]> Stars_XRBuffer;
 
 std::unique_ptr<star[]> Stars_XRBuffer;
 
-#ifndef __APPLE_CC__
+#if !defined(__APPLE_CC__) && !defined(__FreeBSD__)
 
 #define XR_MAKE_VERSION_SHORT(major, minor, patch) \
     ((((major) & 0x3ffU) << 20) | (((minor) & 0x3ffU) << 10) | ((patch) & 0x3ffU))
@@ -545,4 +545,4 @@ OpenXRTrackingInfo openxr_start_stereo_frame() { retur
 
 OpenXRTrackingInfo openxr_start_stereo_frame() { return OpenXRTrackingInfo{}; }
 
-#endif
\ No newline at end of file
+#endif
