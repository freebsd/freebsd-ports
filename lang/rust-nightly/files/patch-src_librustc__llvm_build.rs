--- src/librustc_llvm/build.rs.orig	2017-01-18 02:20:03 UTC
+++ src/librustc_llvm/build.rs
@@ -234,6 +234,8 @@ fn main() {
     // OpenBSD has a particular C++ runtime library name
     let stdcppname = if target.contains("openbsd") {
         "estdc++"
+    } else if target.contains("freebsd") {
+        "c++"
     } else {
         "stdc++"
     };
