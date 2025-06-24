When the compiler has "clang" in its name the cc crate will pass
an LLVM target triple to it.  Rust uses a triple that lacks the OS
version and LLVM will default to FreeBSD 9 behavior, i.e., it will
default to libstdc++ which is no longer available in newer releases.

To avoid this issue assume we have a GNU compatible toolchain instead
until LLVM can be updated to use libc++ by default.

https://reviews.llvm.org/D77776

--- vendor/cc-1.0.99/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.0.99/src/tool.rs
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
--- vendor/cc-1.2.0/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.2.0/src/tool.rs
@@ -174,9 +174,7 @@ impl Tool {
 
             match (clang, accepts_cl_style_flags, gcc, emscripten, vxworks) {
                 (clang_cl, true, _, false, false) => Ok(ToolFamily::Msvc { clang_cl }),
-                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Clang {
-                    zig_cc: is_zig_cc(path, cargo_output),
-                }),
+                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Gnu),
                 (false, false, true, _, false) | (_, _, _, _, true) => Ok(ToolFamily::Gnu),
                 (false, false, false, false, false) => {
                     cargo_output.print_warning(&"Compiler family detection failed since it does not define `__clang__`, `__GNUC__`, `__EMSCRIPTEN__` or `__VXWORKS__`, also does not accept cl style flag `-?`, fallback to treating it as GNU");
--- vendor/cc-1.2.16/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.2.16/src/tool.rs
@@ -174,9 +174,7 @@ impl Tool {
 
             match (clang, accepts_cl_style_flags, gcc, emscripten, vxworks) {
                 (clang_cl, true, _, false, false) => Ok(ToolFamily::Msvc { clang_cl }),
-                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Clang {
-                    zig_cc: is_zig_cc(path, cargo_output),
-                }),
+                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Gnu),
                 (false, false, true, _, false) | (_, _, _, _, true) => Ok(ToolFamily::Gnu),
                 (false, false, false, false, false) => {
                     cargo_output.print_warning(&"Compiler family detection failed since it does not define `__clang__`, `__GNUC__`, `__EMSCRIPTEN__` or `__VXWORKS__`, also does not accept cl style flag `-?`, fallback to treating it as GNU");
--- vendor/cc-1.2.17/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.2.17/src/tool.rs
@@ -174,9 +174,7 @@ impl Tool {
 
             match (clang, accepts_cl_style_flags, gcc, emscripten, vxworks) {
                 (clang_cl, true, _, false, false) => Ok(ToolFamily::Msvc { clang_cl }),
-                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Clang {
-                    zig_cc: is_zig_cc(path, cargo_output),
-                }),
+                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Gnu),
                 (false, false, true, _, false) | (_, _, _, _, true) => Ok(ToolFamily::Gnu),
                 (false, false, false, false, false) => {
                     cargo_output.print_warning(&"Compiler family detection failed since it does not define `__clang__`, `__GNUC__`, `__EMSCRIPTEN__` or `__VXWORKS__`, also does not accept cl style flag `-?`, fallback to treating it as GNU");
--- vendor/cc-1.2.21/src/tool.rs.orig	2024-05-09 18:20:47 UTC
+++ vendor/cc-1.2.21/src/tool.rs
@@ -174,9 +174,7 @@ impl Tool {
 
             match (clang, accepts_cl_style_flags, gcc, emscripten, vxworks) {
                 (clang_cl, true, _, false, false) => Ok(ToolFamily::Msvc { clang_cl }),
-                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Clang {
-                    zig_cc: is_zig_cc(path, cargo_output),
-                }),
+                (true, _, _, _, false) | (_, _, _, true, false) => Ok(ToolFamily::Gnu),
                 (false, false, true, _, false) | (_, _, _, _, true) => Ok(ToolFamily::Gnu),
                 (false, false, false, false, false) => {
                     cargo_output.print_warning(&"Compiler family detection failed since it does not define `__clang__`, `__GNUC__`, `__EMSCRIPTEN__` or `__VXWORKS__`, also does not accept cl style flag `-?`, fallback to treating it as GNU");
