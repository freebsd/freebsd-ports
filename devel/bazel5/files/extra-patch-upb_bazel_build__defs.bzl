--- bazel/build_defs.bzl.orig	2022-01-20 13:04:32.306692000 +0100
+++ bazel/build_defs.bzl	2022-01-20 13:05:02.002057000 +0100
@@ -35,6 +35,7 @@
         # "-Wshorten-64-to-32",  # not in GCC (and my Kokoro images doesn't have Clang)
         "-Werror",
         "-Wno-long-long",
+        "-Wno-deprecated-copy",
         # copybara:strip_end
     ],
 })
