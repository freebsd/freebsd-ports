--- cargo-crates/minidumper-0.8.3/src/ipc/client.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/minidumper-0.8.3/src/ipc/client.rs
@@ -25,11 +25,12 @@ impl Client {
         let sn = name.into();
 
         cfg_if::cfg_if! {
-            if #[cfg(any(target_os = "linux", target_os = "android"))] {
+            if #[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))] {
                 let socket_addr = match sn {
                     SocketName::Path(path) => {
                         uds::UnixSocketAddr::from_path(path).map_err(|_err| Error::InvalidName)?
                     }
+                    #[cfg(any(target_os = "linux", target_os = "android"))]
                     SocketName::Abstract(name) => {
                         uds::UnixSocketAddr::from_abstract(name).map_err(|_err| Error::InvalidName)?
                     }
@@ -99,7 +100,7 @@ impl Client {
     /// this method
     pub fn request_dump(&self, crash_context: &crash_context::CrashContext) -> Result<(), Error> {
         cfg_if::cfg_if! {
-            if #[cfg(any(target_os = "linux", target_os = "android"))] {
+            if #[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))] {
                 let crash_ctx_buffer = crash_context.as_bytes();
             } else if #[cfg(target_os = "windows")] {
                 use scroll::Pwrite;
