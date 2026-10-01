--- bazel/toolchains/cc/mongo_compiler_flags.bzl.orig	2026-09-29 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_compiler_flags.bzl
@@ -77,9 +77,18 @@ def package_specific_linkflag(package_name):
 
 MONGO_GLOBAL_COPTS = MONGO_LINUX_CC_COPTS + MONGO_WIN_CC_COPTS
 
+def freebsd_cxx_standard_copt(package_name):
+    if package_name.startswith("src/mongo"):
+        return select({
+            "@platforms//os:freebsd": ["-std=c++20"],
+            "//conditions:default": [],
+        })
+    return []
+
 def get_copts(name, package_name, copts = [], skip_windows_crt_flags = False):
     copts = MONGO_GLOBAL_COPTS + \
+            freebsd_cxx_standard_copt(package_name) + \
             package_specific_copt(package_name) + \
             copts + \
             force_includes_copt(package_name, name)
