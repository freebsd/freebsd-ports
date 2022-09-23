Avoid loading of "requirements.bzl" because it requires "pip_import" which
is already disabled in "defs.bzl".

--- python/binary.bzl.orig	2022-06-05 09:58:33 UTC
+++ python/binary.bzl
@@ -1,5 +1,5 @@ load("@bazel_skylib//rules:copy_file.bzl", "copy_file"
 load("@bazel_skylib//rules:copy_file.bzl", "copy_file")
-load("@py_deps//:requirements.bzl", "requirement")
+#load("@py_deps//:requirements.bzl", "requirement")
 
 def pip_binary(name, pkg = None):
     "Expose a binary from pip as an executable for linting. Does not work on Windows."
@@ -9,7 +9,8 @@ def pip_binary(name, pkg = None):
 
     native.alias(
         name = name,
-        actual = requirement(pkg).replace(":pkg", ":rules_python_wheel_entry_point_" + name),
+        #actual = requirement(pkg).replace(":pkg", ":rules_python_wheel_entry_point_" + name),
+	actual = "",
         visibility = ["//visibility:public"],
         tags = ["manual"],
     )
