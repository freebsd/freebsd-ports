--- a/bazel/grpc_deps.bzl.orig	2021-10-11 15:54:07.083144000 +0200
+++ b/bazel/grpc_deps.bzl	2021-10-11 16:02:48.722952000 +0200
@@ -239,6 +239,7 @@
     if "com_google_absl" not in native.existing_rules():
         http_archive(
             name = "com_google_absl",
+            patches = ["//third_party/grpc:extra-patch-absl_base_internal_unscaledcycleclock.cc"],
             sha256 = "f368a8476f4e2e0eccf8a7318b98dafbe30b2600f4e3cf52636e5eb145aba06a",
             strip_prefix = "abseil-cpp-df3ea785d8c30a9503321a3d35ee7d35808f190d",
             urls = [
