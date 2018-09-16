--- src/libstd/build.rs.orig	2018-09-03 18:29:12 UTC
+++ src/libstd/build.rs
@@ -94,13 +94,18 @@ fn build_libbacktrace(target: &str) -> Result<(), ()> 
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
 
     if target.contains("darwin") {
         build.file("../libbacktrace/macho.c");
