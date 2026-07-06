--- src/cmd/src/bin/greptime.rs.orig	2026-04-08 15:15:27 UTC
+++ src/cmd/src/bin/greptime.rs
@@ -62,7 +62,7 @@ enum SubCommand {
     Cli(cli::Command),
 }

-#[cfg(not(windows))]
+#[cfg(not(any(windows, target_os = "freebsd")))]
 #[global_allocator]
 static ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
 
