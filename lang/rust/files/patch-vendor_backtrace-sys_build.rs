https://github.com/rust-lang/backtrace-rs/pull/294

--- vendor/backtrace-sys/build.rs.orig	2020-02-19 21:11:31 UTC
+++ vendor/backtrace-sys/build.rs
@@ -60,6 +60,12 @@ fn main() {
     File::create(out_dir.join("config.h")).unwrap();
     if target.contains("android") {
         maybe_enable_dl_iterate_phdr_android(&mut build);
+    } else if target.contains("freebsd") {
+        build.define("HAVE_DL_ITERATE_PHDR", "1");
+        build.define("HAVE_KERN_PROC", "1");
+    } else if target.contains("netbsd") {
+        build.define("HAVE_DL_ITERATE_PHDR", "1");
+        build.define("HAVE_KERN_PROC_ARGS", "1");
     } else if !target.contains("apple-ios")
         && !target.contains("solaris")
         && !target.contains("redox")
