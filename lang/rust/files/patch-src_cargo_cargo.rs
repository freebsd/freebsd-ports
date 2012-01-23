--- src/cargo/cargo.rs.orig	2012-01-22 03:39:41.002804510 +0800
+++ src/cargo/cargo.rs	2012-01-22 09:19:29.018803328 +0800
@@ -389,7 +389,8 @@
     let exec_suffix = os::exec_suffix();
     for ct: str in new {
         if (exec_suffix != "" && str::ends_with(ct, exec_suffix)) ||
-            (exec_suffix == "" && !str::starts_with(ct, "./lib")) {
+            (exec_suffix == "" && !str::starts_with(fs::basename(ct),
+                                                    "lib")) {
             #debug("  bin: %s", ct);
             // FIXME: need libstd fs::copy or something
             run::run_program("cp", [ct, c.bindir]);
