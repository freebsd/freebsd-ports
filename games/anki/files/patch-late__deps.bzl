Avoid loading of "requirements.bzl" because it requires "pip_import" which
is already disabled in "defs.bzl".

--- late_deps.bzl.orig	2021-05-04 05:04:50 UTC
+++ late_deps.bzl
@@ -1,8 +1,6 @@
 """Repo setup that can't happen until after defs.bzl:setup_deps() is run."""
 
-load("@py_deps//:requirements.bzl", "pip_install")
 load("@npm//@bazel/labs:package.bzl", "npm_bazel_labs_dependencies")
 
 def setup_late_deps():
-    pip_install()
     npm_bazel_labs_dependencies()
