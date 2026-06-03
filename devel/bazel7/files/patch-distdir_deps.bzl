--- distdir_deps.bzl.orig	1980-01-01 00:00:00 UTC
+++ distdir_deps.bzl
@@ -167,6 +167,7 @@ DIST_DEPS = {
         "patch_args": ["-p1"],
         "patches": [
             "//third_party/grpc:grpc_1.48.1.patch",
+            "//third_party/grpc:extra-patch-grpc_bazel_grpc__deps.bzl",
             "//third_party/grpc:grpc_1.48.1.win_arm64.patch",
         ],
         "used_in": [
@@ -278,6 +279,9 @@ DIST_DEPS = {
         "urls": [
             "https://mirror.bazel.build/github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz",
             "https://github.com/abseil/abseil-cpp/archive/refs/tags/20220623.1.tar.gz",
+        ],
+        "patches": [
+            "//third_party/py/abseil:extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965",
         ],
         "used_in": [
             "additional_distfiles",
