--- bazel/mongo_src_rules.bzl.orig	2026-08-11 19:14:56 UTC
+++ bazel/mongo_src_rules.bzl
@@ -269,6 +269,9 @@ def force_includes_hdr(package_name, name):
             "//bazel/config:linux_ppc64le": ["//src/third_party/mozjs:platform/ppc64le/linux/build/js-config.h"],
             "//bazel/config:linux_s390x": ["//src/third_party/mozjs:platform/s390x/linux/build/js-config.h"],
             "//bazel/config:linux_x86_64": ["//src/third_party/mozjs:platform/x86_64/linux/build/js-config.h"],
+            "//bazel/config:freebsd_aarch64": ["//src/third_party/mozjs:platform/aarch64/freebsd/build/js-config.h"],
+            "//bazel/config:freebsd_ppc64le": ["//src/third_party/mozjs:platform/ppc64le/freebsd/build/js-config.h"],
+            "//bazel/config:freebsd_x86_64": ["//src/third_party/mozjs:platform/x86_64/freebsd/build/js-config.h"],
             "//bazel/config:macos_aarch64": ["//src/third_party/mozjs:platform/aarch64/macOS/build/js-config.h"],
             "//bazel/config:macos_x86_64": ["//src/third_party/mozjs:platform/x86_64/macOS/build/js-config.h"],
             "//bazel/config:windows_x86_64": ["//src/third_party/mozjs:/platform/x86_64/windows/build/js-config.h"],
@@ -639,6 +642,9 @@ def _mongo_cc_binary_and_test(
         "//bazel/config:linux_ppc64le": linux_rpath_flags,
         "//bazel/config:linux_s390x": linux_rpath_flags,
         "//bazel/config:linux_x86_64": linux_rpath_flags,
+        "//bazel/config:freebsd_aarch64": linux_rpath_flags,
+        "//bazel/config:freebsd_ppc64le": linux_rpath_flags,
+        "//bazel/config:freebsd_x86_64": linux_rpath_flags,
         "//bazel/config:macos_aarch64": macos_rpath_flags,
         "//bazel/config:macos_x86_64": macos_rpath_flags,
         "//bazel/config:windows_x86_64": [],
