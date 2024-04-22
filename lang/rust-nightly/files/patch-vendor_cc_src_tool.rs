When the compiler has "clang" in its name the cc crate will pass
an LLVM target triple to it.  Rust uses a triple that lacks the OS
version and LLVM will default to FreeBSD 9 behavior, i.e., it will
default to libstdc++ which is no longer available in newer releases.

To avoid this issue assume we have a GNU compatible toolchain instead
until LLVM can be updated to use libc++ by default.

https://reviews.llvm.org/D77776

--- vendor/cc/src/tool.rs.orig	2024-03-18 11:23:17 UTC
+++ vendor/cc/src/tool.rs
@@ -122,22 +122,7 @@ impl Tool {
         };
 
         // Try to detect family of the tool from its name, falling back to Gnu.
-        let family = if let Some(fname) = path.file_name().and_then(|p| p.to_str()) {
-            if fname.contains("clang-cl") {
-                ToolFamily::Msvc { clang_cl: true }
-            } else if fname.ends_with("cl") || fname == "cl.exe" {
-                ToolFamily::Msvc { clang_cl: false }
-            } else if fname.contains("clang") {
-                match clang_driver {
-                    Some("cl") => ToolFamily::Msvc { clang_cl: true },
-                    _ => ToolFamily::Clang,
-                }
-            } else {
-                detect_family(&path)
-            }
-        } else {
-            detect_family(&path)
-        };
+        let family = ToolFamily::Gnu;
 
         Tool {
             path,
