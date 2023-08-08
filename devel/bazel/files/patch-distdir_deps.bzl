--- distdir_deps.bzl.orig	1980-01-01 05:00:00 UTC
+++ distdir_deps.bzl
@@ -122,6 +122,7 @@ DIST_DEPS = {
         "patch_args": ["-p1"],
         "patches": [
             "//third_party/grpc:grpc_1.47.0.patch",
+            "//third_party/grpc:extra-patch-grpc_bazel_grpc__deps.bzl",
             "//third_party/grpc:grpc_1.47.0.win_arm64.patch",
         ],
         "used_in": [
@@ -234,6 +235,10 @@ DIST_DEPS = {
         "urls": [
             "https://mirror.bazel.build/github.com/abseil/abseil-cpp/archive/refs/tags/20211102.0.tar.gz",
             "https://github.com/abseil/abseil-cpp/archive/refs/tags/20211102.0.tar.gz",
+        ],
+        "patches": [
+            "//third_party/py/abseil:extra-patch-abseil-cpp_absl_base_internal_unscaledcycleclock.cc",
+            "//third_party/py/abseil:extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965",
         ],
         "used_in": [
             "additional_distfiles",
