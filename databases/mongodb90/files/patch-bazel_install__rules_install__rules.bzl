--- bazel/install_rules/install_rules.bzl.orig	2026-08-11 19:14:56 UTC
+++ bazel/install_rules/install_rules.bzl
@@ -126,13 +126,16 @@ def get_constraints(ctx):
     linux_constraint = ctx.attr._linux_constraint[platform_common.ConstraintValueInfo]
     macos_constraint = ctx.attr._macos_constraint[platform_common.ConstraintValueInfo]
     windows_constraint = ctx.attr._windows_constraint[platform_common.ConstraintValueInfo]
-    return linux_constraint, macos_constraint, windows_constraint
+    freebsd_constraint = ctx.attr._freebsd_constraint[platform_common.ConstraintValueInfo]
+    return linux_constraint, macos_constraint, windows_constraint, freebsd_constraint
 
 def _platform_kind(ctx):
-    linux_constraint, macos_constraint, windows_constraint = get_constraints(ctx)
+    linux_constraint, macos_constraint, windows_constraint, freebsd_constraint = get_constraints(ctx)
     if ctx.target_platform_has_constraint(linux_constraint):
         return "linux"
+    if ctx.target_platform_has_constraint(freebsd_constraint):
+        return "linux"
     if ctx.target_platform_has_constraint(macos_constraint):
         return "macos"
     if ctx.target_platform_has_constraint(windows_constraint):
         return "windows"
@@ -481,6 +484,7 @@ mongo_install_rule = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
     },
     doc = "Install targets",
     toolchains = ["@rules_python//python:toolchain_type"],
