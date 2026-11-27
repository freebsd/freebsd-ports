--- crates/project/src/agent_registry_store.rs.orig	2026-11-25 15:48:16 UTC
+++ crates/project/src/agent_registry_store.rs
@@ -606,6 +606,8 @@ fn platform_keys(os: &str, arch: &str, prefers_musl: b
         ("windows", "x86_64", _) => &["windows-x86_64"],
         ("linux", "aarch64", false) => &["linux-aarch64"],
         ("linux", "x86_64", false) => &["linux-x86_64"],
+        ("freebsd", "aarch64", _) => &["freebsd-aarch64"],
+        ("freebsd", "x86_64", _) => &["freebsd-x86_64"],
         // Not every agent publishes a musl build, and the glibc one may still
         // run through a compatibility layer, so keep it as a fallback.
         ("linux", "aarch64", true) => &["linux-aarch64-musl", "linux-aarch64"],
