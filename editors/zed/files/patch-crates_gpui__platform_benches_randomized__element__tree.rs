--- crates/gpui_platform/benches/randomized_element_tree.rs.orig	2026-11-20 15:11:38 UTC
+++ crates/gpui_platform/benches/randomized_element_tree.rs
@@ -988,7 +988,7 @@ fn text_shaping_available() -> bool {
 /// Without it, text workloads paint no glyphs, so they are skipped rather than measured.
 fn text_shaping_available() -> bool {
     if cfg!(all(
-        target_os = "linux",
+        any(target_os = "linux", target_os = "freebsd"),
         not(any(feature = "x11", feature = "wayland"))
     )) {
         eprintln!("text benchmarks require x11 or wayland on Linux for production text shaping");
