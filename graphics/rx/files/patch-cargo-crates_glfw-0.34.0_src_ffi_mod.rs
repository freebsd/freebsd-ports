--- cargo-crates/glfw-0.34.0/src/ffi/mod.rs.orig	2020-01-18 07:50:25 UTC
+++ cargo-crates/glfw-0.34.0/src/ffi/mod.rs
@@ -574,7 +574,7 @@ extern "C" {
     #[cfg(target_os="macos")] pub fn glfwGetCocoaWindow(window: *mut GLFWwindow) -> *mut c_void;
     #[cfg(target_os="macos")] pub fn glfwGetNSGLContext(window: *mut GLFWwindow) -> *mut c_void;
 
-    #[cfg(target_os="linux")] pub fn glfwGetX11Window(window: *mut GLFWwindow) -> *mut c_void;
-    #[cfg(target_os="linux")] pub fn glfwGetX11Display() -> *mut c_void;
-    #[cfg(target_os="linux")] pub fn glfwGetGLXContext(window: *mut GLFWwindow) -> *mut c_void;
+    #[cfg(target_os="freebsd")] pub fn glfwGetX11Window(window: *mut GLFWwindow) -> *mut c_void;
+    #[cfg(target_os="freebsd")] pub fn glfwGetX11Display() -> *mut c_void;
+    #[cfg(target_os="freebsd")] pub fn glfwGetGLXContext(window: *mut GLFWwindow) -> *mut c_void;
 }
