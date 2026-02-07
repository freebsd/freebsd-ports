--- src/bootstrap/src/core/config/config.rs.orig	2025-08-24 19:46:17 UTC
+++ src/bootstrap/src/core/config/config.rs
@@ -1991,9 +1991,9 @@ pub fn check_stage0_version(
                 || source_version.minor == stage0_version.minor + 1)))
     {
         let prev_version = format!("{}.{}.x", source_version.major, source_version.minor - 1);
-        fail(&format!(
+        eprintln!(
             "Unexpected {component_name} version: {stage0_version}, we should use {prev_version}/{source_version} to build source with {source_version}"
-        ));
+        );
     }
 }
 
