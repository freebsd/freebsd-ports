Fix from https://github.com/tokio-rs/mio/commit/87d72418338a9250f70cb4a43c8bea10371f8256.patch

From 87d72418338a9250f70cb4a43c8bea10371f8256 Mon Sep 17 00:00:00 2001
From: Thomas de Zeeuw <thomasdezeeuw@gmail.com>
Date: Fri, 17 May 2019 11:52:42 +0200
Subject: [PATCH] Fix kqueue on platforms where C's long is i32

--- cargo-crates/mio-0.6.17/src/sys/unix/kqueue.rs.orig	2019-05-15 23:35:30 UTC
+++ cargo-crates/mio-0.6.17/src/sys/unix/kqueue.rs
@@ -74,7 +74,11 @@ impl Selector {
         let timeout = timeout.map(|to| {
             libc::timespec {
                 tv_sec: cmp::min(to.as_secs(), time_t::max_value() as u64) as time_t,
-                tv_nsec: libc::c_long::from(to.subsec_nanos()),
+                // `Duration::subsec_nanos` is guaranteed to be less than one
+                // billion (the number of nanoseconds in a second), making the
+                // cast to i32 safe. The cast itself is needed for platforms
+                // where C's long is only 32 bits.
+                tv_nsec: libc::c_long::from(to.subsec_nanos() as i32),
             }
         });
         let timeout = timeout.as_ref().map(|s| s as *const _).unwrap_or(ptr::null_mut());
