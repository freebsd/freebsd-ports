--- cargo-crates/crash-context-0.6.3/src/freebsd.rs.orig	2026-03-26 00:35:45 UTC
+++ cargo-crates/crash-context-0.6.3/src/freebsd.rs
@@ -0,0 +1,56 @@
+pub use libc::ucontext_t;
+
+/// The full context for a FreeBSD crash
+#[repr(C)]
+pub struct CrashContext {
+    /// Crashing thread context
+    pub context: libc::ucontext_t,
+    /// The signal info for the crash
+    pub siginfo: libc::siginfo_t,
+    /// The id of the crashing process
+    pub pid: libc::pid_t,
+    /// The id of the crashing thread
+    pub tid: libc::pid_t,
+}
+
+unsafe impl Send for CrashContext {}
+
+impl Clone for CrashContext {
+    fn clone(&self) -> Self {
+        unsafe {
+            let mut new: Self = std::mem::zeroed();
+            std::ptr::copy_nonoverlapping(
+                (self as *const Self).cast::<u8>(),
+                (&mut new as *mut Self).cast::<u8>(),
+                std::mem::size_of::<Self>(),
+            );
+            new
+        }
+    }
+}
+
+impl CrashContext {
+    pub fn as_bytes(&self) -> &[u8] {
+        unsafe {
+            let size = std::mem::size_of_val(self);
+            let ptr = (self as *const Self).cast();
+            std::slice::from_raw_parts(ptr, size)
+        }
+    }
+
+    pub fn from_bytes(bytes: &[u8]) -> Option<Self> {
+        if bytes.len() != std::mem::size_of::<Self>() {
+            return None;
+        }
+
+        unsafe { Some((*bytes.as_ptr().cast::<Self>()).clone()) }
+    }
+}
+
+extern "C" {
+    fn getcontext(ucp: *mut libc::ucontext_t) -> libc::c_int;
+}
+
+pub unsafe fn crash_context_getcontext(context: *mut libc::ucontext_t) -> i32 {
+    unsafe { getcontext(context) }
+}
