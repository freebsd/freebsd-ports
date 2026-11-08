-- Treat FreeBSD like Linux when creating a surface from X11/Wayland present
-- info, which is otherwise rejected as an unsupported platform.
-- Not reported upstream.

--- wgpu/backends/wgpu_native/_helpers.py.orig	2026-10-19 13:06:19 UTC
+++ wgpu/backends/wgpu_native/_helpers.py
@@ -169,7 +169,7 @@ def get_surface_id_from_info(present_info):
         struct.layer = ffi.cast("void *", metal_layer.ptr.value)
         struct.chain.sType = lib.WGPUSType_SurfaceSourceMetalLayer
 
-    elif sys.platform.startswith("linux"):  # no-cover
+    elif sys.platform.startswith(("linux", "freebsd")):  # no-cover
         platform = present_info.get("platform", "x11")
         if platform == "x11":
             struct = ffi.new("WGPUSurfaceSourceXlibWindow *")
