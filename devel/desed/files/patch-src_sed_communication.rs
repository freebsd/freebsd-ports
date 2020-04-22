--- src/sed/communication.rs.orig	2020-04-21 22:56:45 UTC
+++ src/sed/communication.rs
@@ -24,7 +24,7 @@ impl SedCommunicator {
         });
     }
     fn get_sed_output(&self) -> Result<String, String> {
-        let sed_debug_command = Command::new("sed")
+        let sed_debug_command = Command::new("gsed")
             .args(
                 self.options.sed_parameters.iter().map(|s| s.as_str())
                 .chain(
