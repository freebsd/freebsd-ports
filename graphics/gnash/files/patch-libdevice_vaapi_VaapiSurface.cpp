--- libdevice/vaapi/VaapiSurface.cpp.orig	2012-01-19 20:17:48.000000000 +0100
+++ libdevice/vaapi/VaapiSurface.cpp	2013-07-05 01:44:21.927681308 +0200
@@ -62,8 +62,8 @@
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
