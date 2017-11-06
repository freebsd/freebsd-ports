--- src/librustc_llvm/build.rs.orig	2017-06-06 00:42:59 UTC
+++ src/librustc_llvm/build.rs
@@ -241,6 +241,8 @@ fn main() {
     let stdcppname = if target.contains("openbsd") {
         // OpenBSD has a particular C++ runtime library name
         "estdc++"
+    } else if target.contains("freebsd") {
+        "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
         "stdc++_pic"
