--- distdir_deps.bzl.orig	1979-12-31 23:00:00 UTC
+++ distdir_deps.bzl
@@ -130,6 +130,7 @@ DIST_DEPS = {
         "patch_args": ["-p1"],
         "patches": [
             "//third_party/grpc:grpc_1.41.0.patch",
+            "//third_party/grpc:extra-patch-bazel_grpc__deps.bzl",
             "//third_party/grpc:grpc_1.41.0.win_arm64.patch",
         ],
         "used_in": [
@@ -168,6 +169,9 @@ DIST_DEPS = {
             "https://mirror.bazel.build/github.com/abseil/abseil-cpp/archive/refs/tags/20211102.0.tar.gz",
             "https://github.com/abseil/abseil-cpp/archive/refs/tags/20211102.0.tar.gz",
         ],
+	"patches": [
+            "//third_party/py/abseil:extra-patch-absl_base_internal_unscaledcycleclock.cc",
+	],
         "used_in": [
             "additional_distfiles",
             "test_WORKSPACE_files",
