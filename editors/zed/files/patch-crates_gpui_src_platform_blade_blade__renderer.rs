--- crates/gpui/src/platform/blade/blade_renderer.rs.orig	2026-01-14 15:30:09 UTC
+++ crates/gpui/src/platform/blade/blade_renderer.rs
@@ -477,7 +477,7 @@ impl BladeRenderer {
             && !self.gpu.wait_for(&last_sp, MAX_FRAME_TIME_MS)
         {
             log::error!("GPU hung");
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
             if self.gpu.device_information().driver_name == "radv" {
                 log::error!(
                     "there's a known bug with amdgpu/radv, try setting ZED_PATH_SAMPLE_COUNT=0 as a workaround"
