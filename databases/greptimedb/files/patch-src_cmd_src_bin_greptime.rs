--- src/cmd/src/bin/greptime.rs.orig	2026-09-16 03:17:27 UTC
+++ src/cmd/src/bin/greptime.rs
@@ -66,7 +66,7 @@ enum SubCommand {
     User(user::Command),
 }
 
-#[cfg(not(windows))]
+#[cfg(not(any(windows, target_os = "freebsd")))]
 #[global_allocator]
 static ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
 
