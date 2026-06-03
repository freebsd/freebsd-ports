--- src/xdg.rs.orig	2025-11-04 01:20:43 UTC
+++ src/xdg.rs
@@ -26,7 +26,7 @@ pub fn xdg_dirs(xdg_type: &str, def_home_suffix: &str,
 }
 
 /// Return configuration directories for UNIX systems
-pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:/etc") }
+pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:%%PREFIX%%/etc") }
 
 /// Return syntax directories for UNIX systems
 pub fn data_dirs() -> Vec<String> {
