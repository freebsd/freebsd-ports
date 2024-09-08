When the compiler has "clang" in its name the cc crate will pass
an LLVM target triple to it.  Rust uses a triple that lacks the OS
version and LLVM will default to FreeBSD 9 behavior, i.e., it will
default to libstdc++ which is no longer available in newer releases.

To avoid this issue assume we have a GNU compatible toolchain instead
until LLVM can be updated to use libc++ by default.

https://reviews.llvm.org/D77776

--- vendor/cc-1.0.79/src/lib.rs.orig	2021-03-04 20:58:54 UTC
+++ vendor/cc-1.0.79/src/lib.rs
@@ -2659,24 +2659,7 @@ impl Tool {
     }
 
     fn with_features(path: PathBuf, clang_driver: Option<&str>, cuda: bool) -> Self {
-        // Try to detect family of the tool from its name, falling back to Gnu.
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
-                ToolFamily::Gnu
-            }
-        } else {
-            ToolFamily::Gnu
-        };
-
+        let family = ToolFamily::Gnu;
         Tool {
             path: path,
             cc_wrapper_path: None,

--- vendor/cc-1.0.90/src/tool.rs.orig	2024-03-18 11:23:17 UTC
+++ vendor/cc-1.0.90/src/tool.rs
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
--- vendor/cc-1.0.97/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.0.97/src/tool.rs
@@ -151,9 +151,7 @@ impl Tool {
 
             match (clang, accepts_cl_style_flags, gcc) {
                 (clang_cl, true, _) => Ok(ToolFamily::Msvc { clang_cl }),
-                (true, false, _) => Ok(ToolFamily::Clang {
-                    zig_cc: is_zig_cc(path, cargo_output),
-                }),
+                (true, false, _) => Ok(ToolFamily::Gnu),
                 (false, false, true) => Ok(ToolFamily::Gnu),
                 (false, false, false) => {
                     cargo_output.print_warning(&"Compiler family detection failed since it does not define `__clang__`, `__GNUC__` or `_MSC_VER`, fallback to treating it as GNU");
