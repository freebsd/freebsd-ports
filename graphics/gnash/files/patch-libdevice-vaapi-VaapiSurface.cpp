--- libdevice/vaapi/VaapiSurface.cpp.orig	2016-07-21 12:25:09 UTC
+++ libdevice/vaapi/VaapiSurface.cpp
@@ -62,8 +62,8 @@ public:
     VAStatus status;
     VASurfaceID surface_id;
     status = vaCreateSurfaces(gvactx->display(),
-                              width, height, VA_RT_FORMAT_YUV420,
-                              1, &surface_id);
+                              VA_RT_FORMAT_YUV420, width, height,
+                              &surface_id, 1, NULL, 0);
     if (!vaapi_check_status(status, "vaCreateSurfaces()")) {
         return;
     }
