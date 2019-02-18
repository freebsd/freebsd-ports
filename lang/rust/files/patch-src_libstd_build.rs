--- src/libstd/build.rs.orig	2019-01-16 09:30:27 UTC
+++ src/libstd/build.rs
@@ -92,13 +92,18 @@ fn build_libbacktrace(target: &str) -> Result<(), ()> 
         .out_dir(&native.out_dir)
         .warnings(false)
         .file("../libbacktrace/alloc.c")
-        .file("../libbacktrace/backtrace.c")
         .file("../libbacktrace/dwarf.c")
         .file("../libbacktrace/fileline.c")
         .file("../libbacktrace/posix.c")
         .file("../libbacktrace/read.c")
         .file("../libbacktrace/sort.c")
         .file("../libbacktrace/state.c");
+
+    if target.contains("freebsd") {
+        build.file("../libbacktrace/nounwind.c");
+    } else {
+        build.file("../libbacktrace/backtrace.c");
+    }
 
     let any_debug = env::var("RUSTC_DEBUGINFO").unwrap_or_default() == "true" ||
         env::var("RUSTC_DEBUGINFO_LINES").unwrap_or_default() == "true";
