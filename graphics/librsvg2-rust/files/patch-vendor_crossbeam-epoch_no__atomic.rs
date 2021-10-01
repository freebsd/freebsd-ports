--- vendor/crossbeam-epoch/no_atomic.rs.orig	2021-09-16 01:15:26 UTC
+++ vendor/crossbeam-epoch/no_atomic.rs
@@ -30,6 +30,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
+    "powerpc-unknown-freebsd",
     "powerpc-unknown-linux-gnu",
     "powerpc-unknown-linux-gnuspe",
     "powerpc-unknown-linux-musl",
