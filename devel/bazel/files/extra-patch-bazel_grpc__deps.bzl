--- a/bazel/grpc_deps.bzl
+++ b/bazel/grpc_deps.bzl
@@ -284,6 +284,7 @@
         http_archive(
             name = "com_google_absl",
             sha256 = "35f22ef5cb286f09954b7cc4c85b5a3f6221c9d4df6b8c4a1e9d399555b366ee",
+            patches = ["//third_party/grpc:extra-patch-absl_base_internal_unscaledcycleclock.cc"],
             strip_prefix = "abseil-cpp-997aaf3a28308eba1b9156aa35ab7bca9688e9f6",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/abseil/abseil-cpp/archive/997aaf3a28308eba1b9156aa35ab7bca9688e9f6.tar.gz",
@@ -339,6 +340,7 @@
         http_archive(
             name = "upb",
             sha256 = "6a5f67874af66b239b709c572ac1a5a00fdb1b29beaf13c3e6f79b1ba10dc7c4",
+            patches = ["//third_party/grpc:extra-patch-bazel_build_defs.bzl"],
             strip_prefix = "upb-2de300726a1ba2de9a468468dc5ff9ed17a3215f",
             urls = [
                 "https://storage.googleapis.com/grpc-bazel-mirror/github.com/protocolbuffers/upb/archive/2de300726a1ba2de9a468468dc5ff9ed17a3215f.tar.gz",
