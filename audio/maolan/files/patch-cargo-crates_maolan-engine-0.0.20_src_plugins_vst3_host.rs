--- cargo-crates/maolan-engine-0.0.20/src/plugins/vst3/host.rs.orig	2026-05-28 09:11:22 UTC
+++ cargo-crates/maolan-engine-0.0.20/src/plugins/vst3/host.rs
@@ -179,7 +179,7 @@ fn class_info_to_plugin_info(
     }
 }
 
-fn tuid_to_string(tuid: &[i8; 16]) -> String {
+fn tuid_to_string(tuid: &[std::os::raw::c_char; 16]) -> String {
     // Convert TUID to hexadecimal string
     tuid.iter()
         .map(|&b| format!("{:02X}", b as u8))
@@ -204,7 +204,7 @@ mod tests {
         let class_info = ClassInfo {
             name: "Synth".to_string(),
             category: "Instrument".to_string(),
-            cid: [0x12_i8; 16],
+            cid: [0x12_i8 as std::os::raw::c_char; 16],
         };
 
         let info = class_info_to_plugin_info(
