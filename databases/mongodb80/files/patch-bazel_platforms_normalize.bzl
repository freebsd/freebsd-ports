--- bazel/platforms/normalize.bzl.orig	2026-08-11 19:14:56 UTC
+++ bazel/platforms/normalize.bzl
@@ -18,4 +18,5 @@ OS_TO_PLATFORM_MAP = {
     "macos": "@platforms//os:osx",
     "linux": "@platforms//os:linux",
     "windows": "@platforms//os:windows",
+    "freebsd": "@platforms//os:freebsd",
 }
