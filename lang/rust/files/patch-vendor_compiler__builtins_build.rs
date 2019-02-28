--- vendor/compiler_builtins/build.rs.orig	2019-01-16 09:30:44 UTC
+++ vendor/compiler_builtins/build.rs
@@ -308,6 +308,10 @@ mod c {
                 ],
             );
 
+            if target_os == "freebsd" {
+                sources.extend(&["clear_cache.c"]);
+            }
+
             // First of all aeabi_cdcmp and aeabi_cfcmp are never called by LLVM.
             // Second are little-endian only, so build fail on big-endian targets.
             // Temporally workaround: exclude these files for big-endian targets.
