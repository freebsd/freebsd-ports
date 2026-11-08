--- src/build_defs.bzl.orig	2026-10-17 21:16:39 UTC
+++ src/build_defs.bzl
@@ -835,12 +835,14 @@ def mozc_select(
         oss = None,
         android = None,
         apple = None,
+        freebsd = None,
         ios = None,
         chromiumos = None,
         linux = None,
         macos = None,
         oss_android = None,
         oss_linux = None,
+        oss_freebsd = None,
         oss_macos = None,
         oss_windows = None,
         prod = None,
@@ -866,9 +868,11 @@ def mozc_select(
       ios: value for iOS build.
       chromiumos: value for ChromeOS build.
       linux: value for Linux build.
+      freebsd: value for FreeBSD build.
       macos: value for macOS build.
       oss_android: value for OSS Android build.
       oss_linux: value for OSS Linux build.
+      oss_freebsd: value for OSS FreeBSD build.
       oss_macos: value for OSS macOS build.
       oss_windows: value for OSS Windows build.
       prod: value for prod build.
@@ -891,6 +895,7 @@ def mozc_select(
         "//bazel/cc_target_os:linux": _get_value([linux, client, default]),
         "//bazel/cc_target_os:oss_android": _get_value([oss_android, oss, android, client, default]),
         "//bazel/cc_target_os:oss_linux": _get_value([oss_linux, oss, linux, client, default]),
+        "//bazel/cc_target_os:oss_freebsd": _get_value([oss_freebsd, oss_linux, oss, freebsd, linux, client, default]),
         "//bazel/cc_target_os:oss_macos": _get_value([oss_macos, oss, macos, apple, client, default]),
         "//bazel/cc_target_os:oss_windows": _get_value([oss_windows, oss, windows, client, default]),
         "//bazel/cc_target_os:prod_linux": _get_value([prod_linux, prod, oss_linux, oss, linux, client, default]),
