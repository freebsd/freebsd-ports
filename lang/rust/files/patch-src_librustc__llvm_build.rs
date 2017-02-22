--- src/librustc_llvm/build.rs.orig	2017-02-09 01:37:48 UTC
+++ src/librustc_llvm/build.rs
@@ -233,6 +233,8 @@ fn main() {
     // OpenBSD has a particular C++ runtime library name
     let stdcppname = if target.contains("openbsd") {
         "estdc++"
+    } else if target.contains("freebsd") {
+        "c++"
     } else {
         "stdc++"
     };
