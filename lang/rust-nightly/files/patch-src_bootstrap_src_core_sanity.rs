XXX: cc_tool is Gnu here because of patch-vendor_cc.rs. We need to seek need better solution.

--- src/bootstrap/src/core/sanity.rs.orig	2025-09-06 18:37:35 UTC
+++ src/bootstrap/src/core/sanity.rs
@@ -338,12 +338,12 @@ than building it.
             let cc_tool = build.cc_tool(*target);
             if !cc_tool.is_like_clang() && !cc_tool.path().ends_with("emcc") {
                 // emcc works as well
-                panic!(
-                    "Clang is required to build C code for Wasm targets, got `{}` instead\n\
-                    this is because compiler-builtins is configured to build C source. Either \
-                    ensure Clang is used, or adjust this configuration.",
-                    cc_tool.path().display()
-                );
+                //panic!(
+                //    "Clang is required to build C code for Wasm targets, got `{}` instead\n\
+                //    this is because compiler-builtins is configured to build C source. Either \
+                //    ensure Clang is used, or adjust this configuration.",
+                //    cc_tool.path().display()
+                //);
             }
         }
 
