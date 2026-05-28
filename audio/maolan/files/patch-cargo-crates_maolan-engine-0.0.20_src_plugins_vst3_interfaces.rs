--- cargo-crates/maolan-engine-0.0.20/src/plugins/vst3/interfaces.rs.orig	2026-05-28 09:11:22 UTC
+++ cargo-crates/maolan-engine-0.0.20/src/plugins/vst3/interfaces.rs
@@ -193,7 +193,7 @@ impl PluginFactory {
     }
 
     /// Create an instance of a plugin using the trait
-    pub fn create_instance(&self, class_id: &[i8; 16]) -> Result<PluginInstance, String> {
+    pub fn create_instance(&self, class_id: &[std::os::raw::c_char; 16]) -> Result<PluginInstance, String> {
         use vst3::Steinberg::IPluginFactoryTrait;
 
         let mut instance_ptr: *mut c_void = std::ptr::null_mut();
@@ -201,7 +201,7 @@ impl PluginFactory {
         let result = unsafe {
             self.factory.createInstance(
                 class_id.as_ptr(),
-                IComponent::IID.as_ptr() as *const i8,
+                IComponent::IID.as_ptr() as *const std::os::raw::c_char,
                 &mut instance_ptr,
             )
         };
@@ -246,7 +246,7 @@ impl PluginFactory {
 
     pub fn create_edit_controller(
         &self,
-        class_id: &[i8; 16],
+        class_id: &[std::os::raw::c_char; 16],
     ) -> Result<ComPtr<IEditController>, String> {
         use vst3::Steinberg::IPluginFactoryTrait;
 
@@ -255,7 +255,7 @@ impl PluginFactory {
         let result = unsafe {
             self.factory.createInstance(
                 class_id.as_ptr(),
-                IEditController::IID.as_ptr() as *const i8,
+                IEditController::IID.as_ptr() as *const std::os::raw::c_char,
                 &mut instance_ptr,
             )
         };
@@ -293,7 +293,7 @@ pub struct ClassInfo {
 pub struct ClassInfo {
     pub name: String,
     pub category: String,
-    pub cid: [i8; 16],
+    pub cid: [std::os::raw::c_char; 16],
 }
 
 /// Information about the plugin factory
@@ -522,7 +522,7 @@ impl PluginInstance {
             let vtbl = (*component_raw).vtbl;
             let query_interface = (*vtbl).base.base.queryInterface;
             // Cast IID from [u8; 16] to [i8; 16]
-            let iid = std::mem::transmute::<&[u8; 16], &[i8; 16]>(&IAudioProcessor::IID);
+            let iid = std::mem::transmute::<&[u8; 16], &[std::os::raw::c_char; 16]>(&IAudioProcessor::IID);
             query_interface(component_raw as *mut _, iid, &mut processor_ptr)
         };
 
@@ -537,7 +537,7 @@ impl PluginInstance {
             let component_raw = self.component.as_ptr();
             let vtbl = (*component_raw).vtbl;
             let query_interface = (*vtbl).base.base.queryInterface;
-            let iid = std::mem::transmute::<&[u8; 16], &[i8; 16]>(&IEditController::IID);
+            let iid = std::mem::transmute::<&[u8; 16], &[std::os::raw::c_char; 16]>(&IEditController::IID);
             query_interface(component_raw as *mut _, iid, &mut controller_ptr)
         };
         if query_result == kResultOk && !controller_ptr.is_null() {
@@ -1621,7 +1621,7 @@ fn get_module_path(bundle_path: &Path) -> Result<std::
     }
 }
 
-fn extract_cstring(bytes: &[i8]) -> String {
+fn extract_cstring(bytes: &[std::os::raw::c_char]) -> String {
     let len = bytes.iter().position(|&c| c == 0).unwrap_or(bytes.len());
     let u8_bytes: Vec<u8> = bytes[..len].iter().map(|&b| b as u8).collect();
     String::from_utf8_lossy(&u8_bytes).to_string()
@@ -1663,14 +1663,14 @@ mod tests {
 
     #[test]
     fn extract_cstring_stops_at_nul_and_uses_lossy_utf8() {
-        let bytes = [b'A' as i8, b'B' as i8, -1, 0, b'Z' as i8];
+        let bytes = [b'A' as std::os::raw::c_char, b'B' as std::os::raw::c_char, -1i8 as std::os::raw::c_char, 0, b'Z' as std::os::raw::c_char];
 
         assert_eq!(extract_cstring(&bytes), "AB\u{FFFD}");
     }
 
     #[test]
     fn extract_cstring_uses_full_slice_when_not_nul_terminated() {
-        let bytes = [b'X' as i8, b'Y' as i8, b'Z' as i8];
+        let bytes = [b'X' as std::os::raw::c_char, b'Y' as std::os::raw::c_char, b'Z' as std::os::raw::c_char];
 
         assert_eq!(extract_cstring(&bytes), "XYZ");
     }
