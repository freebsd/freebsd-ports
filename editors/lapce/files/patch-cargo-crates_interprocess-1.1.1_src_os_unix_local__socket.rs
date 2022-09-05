--- cargo-crates/interprocess-1.1.1/src/os/unix/local_socket.rs.orig	2022-09-05 13:24:51 UTC
+++ cargo-crates/interprocess-1.1.1/src/os/unix/local_socket.rs
@@ -72,13 +72,13 @@ impl LocalSocketStream {
     }
     #[inline]
     pub fn peer_pid(&self) -> io::Result<u32> {
-        #[cfg(not(any(target_os = "macos", target_os = "ios")))]
+        #[cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios")))]
         {
             self.inner
                 .get_peer_credentials()
                 .map(|ucred| ucred.pid as u32)
         }
-        #[cfg(any(target_os = "macos", target_os = "ios"))]
+        #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
         {
             Err(io::Error::new(io::ErrorKind::Other, "not supported"))
         }
