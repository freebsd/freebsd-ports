--- cargo-crates/interprocess-1.1.1/src/os/unix/udsocket.rs.orig	2022-09-05 13:24:51 UTC
+++ cargo-crates/interprocess-1.1.1/src/os/unix/udsocket.rs
@@ -98,7 +98,7 @@ unsafe fn enable_passcred(socket: i32) -> bool {
 #[inline]
 #[allow(unused_variables)]
 unsafe fn enable_passcred(socket: i32) -> bool {
-    #[cfg(not(any(target_os = "macos", target_os = "ios")))]
+    #[cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios")))]
     {
         let passcred: c_int = 1;
         libc::setsockopt(
@@ -109,12 +109,12 @@ unsafe fn enable_passcred(socket: i32) -> bool {
             mem::size_of_val(&passcred) as u32,
         ) != -1
     }
-    #[cfg(any(target_os = "macos", target_os = "ios"))]
+    #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
     {
         true
     } // Cannot have passcred on macOS and iOS.
 }
-#[cfg(not(any(target_os = "macos", target_os = "ios")))]
+#[cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios")))]
 unsafe fn get_peer_ucred(socket: i32) -> Option<ucred> {
     // SAFETY: it's safe for the ucred structure to be zero-initialized, since
     // it only contains integers
@@ -196,7 +196,7 @@ unsafe fn raw_get_nonblocking(socket: i32) -> Option<b
 /// Sending and receiving ancillary data:
 /// ```no_run
 /// # fn main() -> Result<(), Box<dyn std::error::Error>> {
-/// # #[cfg(all(unix, not(any(target_os = "macos", target_os = "ios"))))] {
+/// # #[cfg(all(unix, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))] {
 /// use interprocess::{
 ///     unnamed_pipe::{pipe, UnnamedPipeReader},
 ///     os::unix::udsocket::{UdStreamListener, UdStream, AncillaryData, AncillaryDataBuf},
@@ -360,7 +360,7 @@ impl UdStreamListener {
     /// # Example
     /// ```no_run
     /// # fn main() -> Result<(), Box<dyn std::error::Error>> {
-    /// # #[cfg(all(unix, not(any(target_os = "macos", target_os = "ios"))))] {
+    /// # #[cfg(all(unix, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))] {
     /// use interprocess::os::unix::udsocket::UdStreamListener;
     ///
     /// let listener = UdStreamListener::bind("/tmp/example.sock")?;
@@ -495,7 +495,7 @@ impl FromRawFd for UdStreamListener {
 /// Receiving and sending ancillary data:
 /// ```no_run
 /// # fn main() -> Result<(), Box<dyn std::error::Error>> {
-/// # #[cfg(all(unix, not(any(target_os = "macos", target_os = "ios"))))] {
+/// # #[cfg(all(unix, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))] {
 /// use interprocess::os::unix::udsocket::{UdStream, AncillaryData, AncillaryDataBuf};
 /// use std::{
 ///     io::{self, prelude::*},
@@ -821,10 +821,10 @@ impl UdStream {
     }
 
     /// Fetches the credentials of the other end of the connection without using ancillary data. The returned structure contains the process identifier, user identifier and group identifier of the peer.
-    #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios"))))]
+    #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))]
     #[cfg_attr(
         feature = "doc_cfg",
-        doc(cfg(not(any(target_os = "macos", target_os = "ios"))))
+        doc(cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))
     )]
     pub fn get_peer_credentials(&self) -> io::Result<ucred> {
         unsafe { get_peer_ucred(self.fd.0).ok_or_else(io::Error::last_os_error) }
@@ -1349,10 +1349,10 @@ impl UdSocket {
     }
 
     /// Fetches the credentials of the other end of the connection without using ancillary data. The returned structure contains the process identifier, user identifier and group identifier of the peer.
-    #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios"))))]
+    #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))]
     #[cfg_attr(
         feature = "doc_cfg",
-        doc(cfg(not(any(target_os = "macos", target_os = "ios"))))
+        doc(cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))))
     )]
     pub fn get_peer_credentials(&self) -> io::Result<ucred> {
         unsafe { get_peer_ucred(self.fd.0).ok_or_else(io::Error::last_os_error) }
@@ -1999,10 +1999,10 @@ pub enum AncillaryData<'a> {
     /// Credentials to be sent. The specified values are checked by the system when sent for all users except for the superuser — for senders, this means that the correct values need to be filled out, otherwise, an error is returned; for receivers, this means that the credentials are to be trusted for authentification purposes. For convenience, the [`credentials`] function provides a value which is known to be valid when sent.
     ///
     /// [`credentials`]: #method.credentials " "
-    #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+    #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
     #[cfg_attr(
         feature = "doc_cfg",
-        doc(cfg(not(any(target_os = "macos", target_os = "ios",)),))
+        doc(cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))
     )]
     Credentials {
         /// The process identificator (PID) for the process.
@@ -2054,7 +2054,7 @@ impl<'a> AncillaryData<'a> {
     pub fn clone_ref(&'a self) -> Self {
         match *self {
             Self::FileDescriptors(ref fds) => Self::FileDescriptors(Cow::Borrowed(&fds)),
-            #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+            #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
             Self::Credentials { pid, uid, gid } => Self::Credentials { pid, uid, gid },
         }
     }
@@ -2064,7 +2064,7 @@ impl<'a> AncillaryData<'a> {
     pub fn encoded_size(&self) -> usize {
         match self {
             Self::FileDescriptors(fds) => Self::encoded_size_of_file_descriptors(fds.len()),
-            #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+            #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
             Self::Credentials { .. } => Self::ENCODED_SIZE_OF_CREDENTIALS,
         }
     }
@@ -2100,7 +2100,7 @@ impl<'a> AncillaryData<'a> {
                         buffer.extend_from_slice(&desc_bytes);
                     }
                 }
-                #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+                #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
                 AncillaryData::Credentials { pid, uid, gid } => {
                     cmsg_type_bytes = SCM_RIGHTS.to_ne_bytes();
                     cmsg_len += mem::size_of::<ucred>();
@@ -2125,10 +2125,10 @@ impl AncillaryData<'static> {
     /// Fetches the credentials of the process from the system and returns a value which can be safely sent to another process without the system complaining about an unauthorized attempt to impersonate another process/user/group.
     ///
     /// If you want to send credentials to another process, this is usually the function you need to obtain the desired ancillary payload.
-    #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+    #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
     #[cfg_attr(
         feature = "doc_cfg",
-        doc(cfg(not(any(target_os = "macos", target_os = "ios",)),))
+        doc(cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))
     )]
     #[inline]
     pub fn credentials() -> Self {
@@ -2350,7 +2350,7 @@ impl<'a> Iterator for AncillaryDataDecoder<'a> {
                 }
                 Some(AncillaryData::FileDescriptors(Cow::Owned(descriptors)))
             }
-            #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+            #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
             SCM_CREDENTIALS => {
                 // We're reading a single ucred structure from the ancillary data payload.
                 // SAFETY: those are still ints
