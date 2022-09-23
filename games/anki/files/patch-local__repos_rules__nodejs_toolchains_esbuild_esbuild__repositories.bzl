Define the FreeBSD esbuild repository (= "freebsd_esbuild_all"), which uses the
esbuild binary, which is built via the "pre-build" target.  Skip the creation
of the remaining esbuild repositories to speed up the processing.

Fix the path to the esbuild package as well otherwise the esbuild JS module
cannot be found during build.

--- local_repos/rules_nodejs/toolchains/esbuild/esbuild_repositories.bzl.orig	2022-07-29 09:05:04 UTC
+++ local_repos/rules_nodejs/toolchains/esbuild/esbuild_repositories.bzl
@@ -45,14 +45,13 @@ def esbuild_repositories(name = "", npm_repository = "
     )
 
     for name, meta in ESBUILD_PACKAGES.platforms.items():
-        _maybe(
-            http_archive,
-            name = "esbuild_%s" % name,
-            urls = meta.urls,
-            strip_prefix = "package",
-            build_file_content = """exports_files(["%s"])""" % meta.binary_path,
-            sha256 = meta.sha,
-        )
+        if name.startswith("freebsd"):
+            native.local_repository(
+                name = "esbuild_freebsd_all",
+                path = "%%_MY_LOCALREPO%%/local_esbuild",
+            )
+        else:
+            continue
 
         toolchain_label = Label("@build_bazel_rules_nodejs//toolchains/esbuild:esbuild_%s_toolchain" % name)
         native.register_toolchains("@%s//%s:%s" % (toolchain_label.workspace_name, toolchain_label.package, toolchain_label.name))
@@ -63,11 +62,6 @@ def esbuild_repositories(name = "", npm_repository = "
     pkg_label = Label("@%s//packages/esbuild:esbuild.bzl" % npm_repository)
     package_path = "external/" + pkg_label.workspace_name + "/@bazel/esbuild"
 
-    # BEGIN-INTERNAL
-    # But when used within rules_nodejs locally from source, it's linked next to the launcher.js source
-    package_path = "packages/esbuild"
-
-    # END-INTERNAL
     npm_install(
         name = "esbuild_npm",
         package_json = Label("@build_bazel_rules_nodejs//toolchains/esbuild:package.json"),
