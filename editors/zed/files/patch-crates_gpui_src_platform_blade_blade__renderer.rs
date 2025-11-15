--- crates/gpui/src/platform/blade/blade_renderer.rs.orig	2025-11-15 06:23:16 UTC
+++ crates/gpui/src/platform/blade/blade_renderer.rs
@@ -436,7 +436,7 @@ impl BladeRenderer {
             && !self.gpu.wait_for(&last_sp, MAX_FRAME_TIME_MS)
         {
             log::error!("GPU hung");
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
             if self.gpu.device_information().driver_name == "radv" {
                 log::error!(
                     "there's a known bug with amdgpu/radv, try setting ZED_PATH_SAMPLE_COUNT=0 as a workaround"
