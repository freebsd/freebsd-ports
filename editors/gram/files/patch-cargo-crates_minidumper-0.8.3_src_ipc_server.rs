--- cargo-crates/minidumper-0.8.3/src/ipc/server.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/minidumper-0.8.3/src/ipc/server.rs
@@ -38,7 +38,7 @@ impl ClientConn {
 
         let mut hdr_buf = [0u8; std::mem::size_of::<Header>()];
         cfg_if::cfg_if! {
-            if #[cfg(any(target_os = "linux", target_os = "android"))] {
+            if #[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))] {
                 let len = self.socket.0.peek(&mut hdr_buf).ok()?;
             } else {
                 let len = self.socket.peek(&mut hdr_buf).ok()?;
@@ -96,11 +96,12 @@ impl Server {
         };
 
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
@@ -312,6 +313,14 @@ impl Server {
                                             if pid.get() != crash_ctx.pid as u32 {
                                                 return Err(Error::UnknownClientPid);
                                             }
+                                        } else if #[cfg(target_os = "freebsd")] {
+                                            // FreeBSD doesn't provide PID via socket credentials; trust the crash context
+                                            let crash_ctx = crash_context::CrashContext::from_bytes(&buffer).ok_or_else(|| {
+                                                Error::from(std::io::Error::new(
+                                                    std::io::ErrorKind::InvalidData,
+                                                    "client sent an incorrectly sized buffer",
+                                                ))
+                                            })?;
                                         } else if #[cfg(target_os = "windows")] {
                                             use scroll::Pread;
                                             let dump_request: super::DumpRequest = buffer.pread(0)?;
@@ -468,10 +477,15 @@ impl Server {
                     minidump_writer::minidump_writer::MinidumpWriter::dump_crash_context(crash_context, None, &mut minidump_file);
             } else if #[cfg(target_os = "macos")] {
                 let mut writer = minidump_writer::minidump_writer::MinidumpWriter::with_crash_context(crash_context);
+            } else if #[cfg(target_os = "freebsd")] {
+                let result: Result<Vec<u8>, std::io::Error> = Err(std::io::Error::new(
+                    std::io::ErrorKind::Unsupported,
+                    "minidump writing not yet supported on FreeBSD",
+                ));
             }
         }
 
-        #[cfg(not(target_os = "windows"))]
+        #[cfg(not(any(target_os = "windows", target_os = "freebsd")))]
         let result = writer.dump(&mut minidump_file);
 
         // Notify the user handler about the minidump, even if we failed to write it
@@ -482,8 +496,10 @@ impl Server {
                     path: minidump_path,
                     #[cfg(target_os = "windows")]
                     contents: None,
-                    #[cfg(not(target_os = "windows"))]
+                    #[cfg(not(any(target_os = "windows", target_os = "freebsd")))]
                     contents: Some(_contents),
+                    #[cfg(target_os = "freebsd")]
+                    contents: None,
                 })
                 .map_err(crate::Error::from),
         ))
