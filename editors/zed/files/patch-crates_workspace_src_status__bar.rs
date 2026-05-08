--- crates/workspace/src/status_bar.rs.orig	2026-05-08 09:37:56 UTC
+++ crates/workspace/src/status_bar.rs
@@ -92,13 +92,13 @@ impl Render for StatusBar {
                     // This border is to avoid a transparent gap in the rounded corners
                     .mb(px(-1.))
                     .mt({
-                        #[cfg(target_os = "linux")]
+                        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                         let needs_gap_fix = {
                             // Running on Wayland and using some scaling levels other than 100% causes a
                             // 1px gap above the status bar; adding a margin avoids this.
                             gpui::guess_compositor() == "Wayland" && window.scale_factor() != 1.0
                         };
-                        #[cfg(not(target_os = "linux"))]
+                        #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
                         let needs_gap_fix = false;
                         if needs_gap_fix { px(-1.) } else { px(0.) }
                     })
