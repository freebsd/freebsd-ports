--- vendor/git2-0.20.0/src/lib.rs.orig	2025-02-21 20:02:44 UTC
+++ vendor/git2-0.20.0/src/lib.rs
@@ -759,6 +759,7 @@ fn init() {
     unix,
     not(target_os = "macos"),
     not(target_os = "ios"),
+    not(target_os = "freebsd"),
     feature = "https"
 ))]
 fn openssl_env_init() {
@@ -880,6 +881,7 @@ fn openssl_env_init() {
     windows,
     target_os = "macos",
     target_os = "ios",
+    target_os = "freebsd",
     not(feature = "https")
 ))]
 fn openssl_env_init() {}
