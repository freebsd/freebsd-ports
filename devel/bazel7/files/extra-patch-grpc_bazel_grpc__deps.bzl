--- a/bazel/grpc_deps.bzl.orig	1980-01-01 00:00:00 UTC
+++ b/bazel/grpc_deps.bzl	2026-03-20 00:00:00 UTC
@@ -295,6 +295,9 @@
         http_archive(
             name = "com_google_absl",
             sha256 = "4208129b49006089ba1d6710845a45e31c59b0ab6bff9e5788a87f55c5abd602",
+            patches = [
+                "//third_party/grpc:extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965",
+            ],
             strip_prefix = "abseil-cpp-20220623.0",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/abseil/abseil-cpp/archive/20220623.0.tar.gz",
@@ -350,6 +353,7 @@
         http_archive(
             name = "upb",
             sha256 = "d0fe259d650bf9547e75896a1307bfc7034195e4ae89f5139814d295991ba681",
+            patches = ["//third_party/grpc:extra-patch-upb_bazel_build__defs.bzl"],
             strip_prefix = "upb-bef53686ec702607971bd3ea4d4fefd80c6cc6e8",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/protocolbuffers/upb/archive/bef53686ec702607971bd3ea4d4fefd80c6cc6e8.tar.gz",
