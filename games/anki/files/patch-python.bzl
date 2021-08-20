Since Bazel 4.2.0 bootstrapping Python stub scripts are prepended with
a "Shebang" expression.

--- python.bzl.orig	2021-08-20 19:05:37 UTC
+++ python.bzl
@@ -27,6 +27,7 @@ py_runtime(
     name = "python_runtime",
     interpreter_path = "{path}",
     python_version = "PY3",
+    stub_shebang = "#!{path}",
     visibility = ["//visibility:public"],
 )
 
