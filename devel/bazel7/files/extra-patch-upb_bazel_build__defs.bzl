--- bazel/build_defs.bzl.orig	2022-06-21 20:39:47 UTC
+++ bazel/build_defs.bzl
@@ -36,6 +36,7 @@ _DEFAULT_CPPOPTS.extend([
     # "-Wshorten-64-to-32",  # not in GCC (and my Kokoro images doesn't have Clang)
     "-Werror",
     "-Wno-long-long",
+    "-Wno-deprecated-copy",
 ])
 _DEFAULT_COPTS.extend([
     "-std=c99",
