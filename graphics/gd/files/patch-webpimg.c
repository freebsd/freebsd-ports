Adjust to libvpx 1.4.0 until the code is removed.

https://chromium.googlesource.com/webm/libvpx/+/9cdaa3d%5E!/
https://bitbucket.org/libgd/gd-libgd/commits/824a3aa

--- src/webpimg.c.orig	2013-06-25 09:58:23 UTC
+++ src/webpimg.c
@@ -711,14 +711,14 @@ static WebPResult VPXEncode(const uint8*
     codec_ctl(&enc, VP8E_SET_STATIC_THRESHOLD, 0);
     codec_ctl(&enc, VP8E_SET_TOKEN_PARTITIONS, 2);
 
-    vpx_img_wrap(&img, IMG_FMT_I420,
+    vpx_img_wrap(&img, VPX_IMG_FMT_I420,
                  y_width, y_height, 16, (uint8*)(Y));
-    img.planes[PLANE_Y] = (uint8*)(Y);
-    img.planes[PLANE_U] = (uint8*)(U);
-    img.planes[PLANE_V] = (uint8*)(V);
-    img.stride[PLANE_Y] = y_stride;
-    img.stride[PLANE_U] = uv_stride;
-    img.stride[PLANE_V] = uv_stride;
+    img.planes[VPX_PLANE_Y] = (uint8*)(Y);
+    img.planes[VPX_PLANE_U] = (uint8*)(U);
+    img.planes[VPX_PLANE_V] = (uint8*)(V);
+    img.stride[VPX_PLANE_Y] = y_stride;
+    img.stride[VPX_PLANE_U] = uv_stride;
+    img.stride[VPX_PLANE_V] = uv_stride;
 
     res = vpx_codec_encode(&enc, &img, 0, 1, 0, VPX_DL_BEST_QUALITY);
 
