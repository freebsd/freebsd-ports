-- use GNU sed instead of BSD sed

--- src/sed/communication.rs.orig	2026-11-09 04:52:33 UTC
+++ src/sed/communication.rs
@@ -25,7 +25,7 @@ impl SedCommunicator {
         })
     }
     fn get_sed_output(&mut self) -> Result<String> {
-        let mut path_to_be_used: &String = &String::from("sed");
+        let mut path_to_be_used: &String = &String::from("gsed");
         if let Some(path) = &self.options.sed_path {
             path_to_be_used = path;
         }
