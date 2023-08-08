From 513f28db0a540725bc41f080a0f52973af67c3db Mon Sep 17 00:00:00 2001
From: MikaelUrankar <mikael.urankar@gmail.com>
Date: Tue, 13 Jun 2023 13:14:06 +0200
Subject: [PATCH] Fix building the documentation on FreeBSD.

It fixes the following error:
error[E0412]: cannot find type `sockcred2` in module `libc`
   --> library/std/src/os/unix/net/ancillary.rs:211:29
    |
211 | pub struct SocketCred(libc::sockcred2);
    |                             ^^^^^^^^^ not found in `libc`
---
 library/std/src/os/unix/net/ancillary.rs | 1 +
 1 file changed, 1 insertion(+)

diff --git a/library/std/src/os/unix/net/ancillary.rs b/library/std/src/os/unix/net/ancillary.rs
index 7565fbc0d099c..814f1c7c2838e 100644
--- library/std/src/os/unix/net/ancillary.rs
+++ library/std/src/os/unix/net/ancillary.rs
@@ -17,6 +17,7 @@ mod libc {
     pub use libc::c_int;
     pub struct ucred;
     pub struct cmsghdr;
+    pub struct sockcred2;
     pub type pid_t = i32;
     pub type gid_t = u32;
     pub type uid_t = u32;
