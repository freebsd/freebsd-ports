--- cargo-crates/pipewire-sys-0.9.2/build.rs.orig	2026-04-19 05:10:06 UTC
+++ cargo-crates/pipewire-sys-0.9.2/build.rs
@@ -20,6 +20,8 @@ fn main() {
         .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
         .size_t_is_usize(true)
         .allowlist_function("pw_.*")
+        .allowlist_function("pipewire_init")
+        .allowlist_function("pipewire_deinit")
         .allowlist_type("pw_.*")
         .allowlist_var("pw_.*")
         .allowlist_var("PW_.*")
