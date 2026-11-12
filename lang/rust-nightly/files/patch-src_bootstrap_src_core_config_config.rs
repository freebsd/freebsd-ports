Do not remove this patch even if the port builds fine without it, as the problem
may return in any future update, when rust version is bumped, but bootstraps are
not updated yet.
--- src/bootstrap/src/core/config/config.rs.orig	2026-11-09 19:07:01 UTC
+++ src/bootstrap/src/core/config/config.rs
@@ -2306,9 +2306,9 @@ fn check_external_binary_version(
                 || source_version.minor == binary_version.minor + 1)))
     {
         let prev_version = format!("{}.{}.x", source_version.major, source_version.minor - 1);
-        fail(&format!(
+        eprintln!(
             "Unexpected {component_name} version: {binary_version}, we should use {prev_version}/{source_version} to build source with {source_version}"
-        ));
+        );
     }
 }
 
