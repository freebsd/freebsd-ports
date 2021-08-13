Avoid loading of Rust and Python PIP rules as both tries to load their
dependencies (cargo crates, Python packages) during the build process.

Also define local repositories to use "www/node" and "www/yarn" from the
Ports tree.

--- defs.bzl.orig	2021-07-30 08:30:37 UTC
+++ defs.bzl
@@ -1,13 +1,11 @@
 load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
 load("@bazel_skylib//lib:versions.bzl", "versions")
-load("@rules_rust//rust:repositories.bzl", "rust_repositories")
 load("@ankidesktop//cargo:crates.bzl", "raze_fetch_remote_crates")
 load(":python.bzl", "setup_local_python")
 load("//proto:protobuf.bzl", "setup_protobuf_binary")
 load("//proto:format.bzl", "setup_clang_format")
 load("@build_bazel_rules_nodejs//:index.bzl", "node_repositories", "yarn_install")
 load("@io_bazel_rules_sass//:defs.bzl", "sass_repositories")
-load("@com_github_ali5h_rules_pip//:defs.bzl", "pip_import")
 load("//pip/pyqt5:defs.bzl", "install_pyqt5")
 load("@esbuild_toolchain//:esbuild_repo.bzl", "esbuild_dependencies")
 
@@ -18,13 +16,6 @@ def setup_deps():
 
     versions.check(minimum_bazel_version = "3.7.0")
 
-    rust_repositories(
-        edition = "2018",
-        include_rustc_srcs = False,
-    )
-
-    raze_fetch_remote_crates()
-
     setup_local_python(name = "python")
 
     setup_protobuf_binary(name = "com_google_protobuf")
@@ -33,18 +24,16 @@ def setup_deps():
 
     native.register_toolchains("@python//:python3_toolchain")
 
-    pip_import(
-        name = "py_deps",
-        requirements = "@ankidesktop//pip:requirements.txt",
-        python_runtime = "@python//:python",
-    )
-
     install_pyqt5(
         name = "pyqt5",
         python_runtime = "@python//:python",
     )
 
-    node_repositories(package_json = ["@ankidesktop//ts:package.json"])
+    node_repositories(
+        package_json = ["@ankidesktop//ts:package.json"],
+	vendored_node = "@local_node//:node",
+	vendored_yarn = "@local_node//:yarn",
+    )
 
     yarn_install(
         name = "npm",
