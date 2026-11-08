--- bazel/toolchains/cc/mongo_wasm/toolchain/wasi_transition.bzl.orig	2026-10-06 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_wasm/toolchain/wasi_transition.bzl
@@ -18,5 +18,6 @@ def _impl(settings, attr):
         "//bazel/config:coverage": False,
         "//command_line_option:copt": [],
+        "//command_line_option:cxxopt": [],
         "//command_line_option:linkopt": [],
     }
 
@@ -40,6 +41,7 @@ wasi_transition = transition(
         "//bazel/config:gcov",
         "//bazel/config:coverage",
         "//command_line_option:copt",
+        "//command_line_option:cxxopt",
         "//command_line_option:linkopt",
     ],
 )
