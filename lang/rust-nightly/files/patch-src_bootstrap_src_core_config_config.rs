--- src/bootstrap/src/core/config/config.rs.orig	2025-06-08 20:17:28 UTC
+++ src/bootstrap/src/core/config/config.rs
@@ -1459,9 +1459,9 @@ impl Config {
                     || source_version.minor == stage0_version.minor + 1)))
         {
             let prev_version = format!("{}.{}.x", source_version.major, source_version.minor - 1);
-            fail(&format!(
+            eprintln!(
                 "Unexpected {component_name} version: {stage0_version}, we should use {prev_version}/{source_version} to build source with {source_version}"
-            ));
+            );
         }
     }
 
