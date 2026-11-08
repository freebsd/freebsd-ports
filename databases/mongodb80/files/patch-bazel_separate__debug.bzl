--- bazel/separate_debug.bzl.orig
+++ bazel/separate_debug.bzl
@@ -561,9 +561,10 @@ def extract_debuginfo_impl(ctx):
 
     linux_constraint = ctx.attr._linux_constraint[platform_common.ConstraintValueInfo]
     macos_constraint = ctx.attr._macos_constraint[platform_common.ConstraintValueInfo]
     windows_constraint = ctx.attr._windows_constraint[platform_common.ConstraintValueInfo]
+    freebsd_constraint = ctx.attr._freebsd_constraint[platform_common.ConstraintValueInfo]
 
-    if ctx.target_platform_has_constraint(linux_constraint):
+    if ctx.target_platform_has_constraint(linux_constraint) or ctx.target_platform_has_constraint(freebsd_constraint):
         # When skipping the archives we have to skip modifying debug info
         # for the intermediates because we end up taking a dependency
         # on the _with_debug .a files
@@ -609,6 +610,7 @@ extract_debuginfo = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
     },
     doc = "Extract debuginfo into a separate file",
     toolchains = ["@bazel_tools//tools/cpp:toolchain_type"],
@@ -641,6 +643,7 @@ extract_debuginfo_binary = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
     },
     doc = "Extract debuginfo into a separate file",
     toolchains = ["@bazel_tools//tools/cpp:toolchain_type"],
@@ -674,6 +677,7 @@ extract_debuginfo_test = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
     },
     doc = "Extract debuginfo into a separate file",
     toolchains = ["@bazel_tools//tools/cpp:toolchain_type"],
