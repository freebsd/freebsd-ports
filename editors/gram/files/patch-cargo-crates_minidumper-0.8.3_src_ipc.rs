--- cargo-crates/minidumper-0.8.3/src/ipc.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/minidumper-0.8.3/src/ipc.rs
@@ -1,5 +1,5 @@ cfg_if::cfg_if! {
 cfg_if::cfg_if! {
-    if #[cfg(any(target_os = "linux", target_os = "android"))] {
+    if #[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))] {
         use std::os::{
             unix::{prelude::{RawFd, BorrowedFd}, io::AsRawFd},
             fd::AsFd,
