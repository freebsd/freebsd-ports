--- src/bootstrap/src/core/config/config.rs.orig	2025-04-01 18:22:03 UTC
+++ src/bootstrap/src/core/config/config.rs
@@ -3016,9 +3016,9 @@ impl Config {
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
 
