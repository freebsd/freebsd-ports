-- Load libwgpu_native.so from the graphics/wgpu-native port on FreeBSD:
-- the sdist does not ship the wgpu-native library and the wheel-only lookup
-- has no FreeBSD platform entry. WGPU_LIB_PATH can still override this.
-- Not reported upstream.

--- wgpu/backends/wgpu_native/_ffi.py.orig	2026-10-19 13:06:19 UTC
+++ wgpu/backends/wgpu_native/_ffi.py
@@ -37,6 +37,9 @@ def get_wgpu_lib_path():
     if override_path:
         return override_path
 
+    if sys.platform.startswith("freebsd"):
+        return "%%LOCALBASE%%/lib/libwgpu_native.so"
+
     # Load the debug binary if requested
     debug_mode = os.getenv("WGPU_DEBUG", "").strip() == "1"
     candidate_builds = ["-debug" if debug_mode else "-release"]
