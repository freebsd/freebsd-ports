--- src/unix.rs.orig	2020-04-24 08:39:34 UTC
+++ src/unix.rs
@@ -39,7 +39,7 @@ fn xdg_dirs(xdg_type: &str, def_home_suffix: &str, def
 }
 
 /// Return configuration directories for UNIX systems
-pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:/etc") }
+pub fn conf_dirs() -> Vec<String> { xdg_dirs("CONFIG", "/.config", "/etc/xdg:%%PREFIX%%/etc") }
 
 /// Return syntax directories for UNIX systems
 pub fn data_dirs() -> Vec<String> {
