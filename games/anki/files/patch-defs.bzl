Avoid loading of Rust and Python PIP rules as both tries to load their
dependencies (cargo crates, Python packages) during the build process.

Also define local repositories to use "www/node" and "www/yarn" from the
Ports tree.

--- defs.bzl.orig	2022-06-24 05:10:06 UTC
+++ defs.bzl
@@ -1,6 +1,5 @@ load("@bazel_skylib//lib:versions.bzl", "versions")
 load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
 load("@bazel_skylib//lib:versions.bzl", "versions")
-load("@rules_rust//rust:repositories.bzl", "rust_repositories")
 load("@ankidesktop//cargo:crates.bzl", "raze_fetch_remote_crates")
 load("//python:python.bzl", "setup_local_python")
 load("//proto:protobuf.bzl", "setup_protobuf_binary")
@@ -17,14 +16,6 @@ def setup_deps():
 
     versions.check(minimum_bazel_version = "3.7.0")
 
-    rust_repositories(
-        edition = "2021",
-        include_rustc_srcs = False,
-        version = "1.58.1",
-    )
-
-    raze_fetch_remote_crates()
-
     setup_local_python(name = "python")
 
     setup_protobuf_binary(name = "com_google_protobuf")
@@ -33,13 +24,6 @@ def setup_deps():
 
     native.register_toolchains("@python//:python3_toolchain")
 
-    pip_parse(
-        name = "py_deps",
-        requirements_lock = "@ankidesktop//python:requirements.txt",
-        python_interpreter_target = "@python//:python",
-        extra_pip_args = ["--require-hashes"],
-    )
-
     install_pyqt(
         name = "pyqt6",
         python_runtime = "@python//:python",
@@ -60,7 +44,9 @@ def setup_deps():
 
     node_repositories(
         package_json = ["@ankidesktop//:package.json"],
-        node_version = "16.13.2",
+        node_version = "16.15.1",
+        vendored_node = "@local_node//:node",
+        vendored_yarn = "@local_node//:yarn",
     )
 
     yarn_install(
