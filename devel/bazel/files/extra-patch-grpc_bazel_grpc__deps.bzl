--- a/bazel/grpc_deps.bzl.orig	2022-06-21 20:39:47 UTC
+++ b/bazel/grpc_deps.bzl
@@ -295,6 +295,10 @@ def grpc_deps():
         http_archive(
             name = "com_google_absl",
             sha256 = "dcf71b9cba8dc0ca9940c4b316a0c796be8fab42b070bb6b7cab62b48f0e66c4",
+            patches = [
+                "//third_party/grpc:extra-patch-abseil-cpp_absl_base_internal_unscaledcycleclock.cc",
+                "//third_party/grpc:extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965",
+            ],
             strip_prefix = "abseil-cpp-20211102.0",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/abseil/abseil-cpp/archive/20211102.0.tar.gz",
@@ -350,6 +354,7 @@ def grpc_deps():
         http_archive(
             name = "upb",
             sha256 = "d0fe259d650bf9547e75896a1307bfc7034195e4ae89f5139814d295991ba681",
+            patches = ["//third_party/grpc:extra-patch-upb_bazel_build__defs.bzl"],
             strip_prefix = "upb-bef53686ec702607971bd3ea4d4fefd80c6cc6e8",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/protocolbuffers/upb/archive/bef53686ec702607971bd3ea4d4fefd80c6cc6e8.tar.gz",
