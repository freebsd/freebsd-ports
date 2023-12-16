--- bazel/build_defs.bzl.orig	2023-08-27 11:49:04.950868000 +0100
+++ bazel/build_defs.bzl	2023-08-27 11:51:17.441304000 +0100
@@ -35,6 +35,7 @@
         # "-Wshorten-64-to-32",  # not in GCC (and my Kokoro images doesn't have Clang)
         "-Werror",
         "-Wno-long-long",
+        "-Wno-deprecated-copy",
         # copybara:strip_end
     ],
 })
@@ -49,6 +50,7 @@
         "-Werror=pedantic",
         "-Wall",
         "-Wstrict-prototypes",
+        "-Wno-gnu-offsetof-extensions",
         # GCC (at least) emits spurious warnings for this that cannot be fixed
         # without introducing redundant initialization (with runtime cost):
         #   https://gcc.gnu.org/bugzilla/show_bug.cgi?id=80635
