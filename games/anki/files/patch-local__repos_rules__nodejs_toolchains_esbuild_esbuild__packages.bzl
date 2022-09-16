Add a stub entry for a pseudo FreeBSD package.  Parts of it are used to serve
as the basis for the esbuild NPM repository containing the wrapper script for
esbuild.

--- local_repos/rules_nodejs/toolchains/esbuild/esbuild_packages.bzl.orig	2022-07-29 09:05:04 UTC
+++ local_repos/rules_nodejs/toolchains/esbuild/esbuild_packages.bzl
@@ -11,6 +11,16 @@ ESBUILD_PACKAGES = struct(
 ESBUILD_PACKAGES = struct(
     version = _VERSION,
     platforms = dict({
+        "freebsd_all": struct(
+            sha = "",
+            urls = [
+                ""
+            ],
+            binary_path = "bin/esbuild",
+            exec_compatible_with = [
+                "@platforms//os:freebsd",
+            ],
+        ),
         "darwin_amd64": struct(
             sha = _DARWIN_AMD64_SHA,
             urls = [
