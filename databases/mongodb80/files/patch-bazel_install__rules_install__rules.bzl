--- bazel/install_rules/install_rules.bzl.orig	2026-08-11 19:14:56 UTC
+++ bazel/install_rules/install_rules.bzl
@@ -103,7 +103,8 @@ def get_constraints(ctx):
     """
     linux_constraint = ctx.attr._linux_constraint[platform_common.ConstraintValueInfo]
     macos_constraint = ctx.attr._macos_constraint[platform_common.ConstraintValueInfo]
     windows_constraint = ctx.attr._windows_constraint[platform_common.ConstraintValueInfo]
-    return linux_constraint, macos_constraint, windows_constraint
+    freebsd_constraint = ctx.attr._freebsd_constraint[platform_common.ConstraintValueInfo]
+    return linux_constraint, macos_constraint, windows_constraint, freebsd_constraint
 
 def is_binary_file(ctx, basename):
@@ -117,7 +118,7 @@ def is_binary_file(ctx, basename):
         True if it looks like a binary, False otherwise
     """
-    linux_constraint, macos_constraint, windows_constraint = get_constraints(ctx)
-    if ctx.target_platform_has_constraint(linux_constraint):
+    linux_constraint, macos_constraint, windows_constraint, freebsd_constraint = get_constraints(ctx)
+    if ctx.target_platform_has_constraint(linux_constraint) or ctx.target_platform_has_constraint(freebsd_constraint):
         return not (basename.startswith("lib") or basename.startswith("mongo_crypt_v") or basename.startswith("stitch_support.so"))
     elif ctx.target_platform_has_constraint(macos_constraint):
         return not (basename.startswith("lib") or basename.startswith("mongo_crypt_v") or basename.startswith("stitch_support.dylib"))
@@ -138,7 +139,7 @@ def is_debug_file(ctx, basename):
         True if it looks like a debug file, False otherwise
     """
-    linux_constraint, macos_constraint, windows_constraint = get_constraints(ctx)
-    if ctx.target_platform_has_constraint(linux_constraint):
+    linux_constraint, macos_constraint, windows_constraint, freebsd_constraint = get_constraints(ctx)
+    if ctx.target_platform_has_constraint(linux_constraint) or ctx.target_platform_has_constraint(freebsd_constraint):
         return basename.endswith(".debug") or basename.endswith(".dwp")
     elif ctx.target_platform_has_constraint(macos_constraint):
         return basename.endswith(".dSYM")
@@ -176,5 +177,5 @@ def sort_file(ctx, file, install_dir, file_map, is_directory):
 
     """
-    _, macos_constraint, _ = get_constraints(ctx)
+    _, macos_constraint, _, _ = get_constraints(ctx)
     basename = paths.basename(file)
     bin_install = install_dir + "/bin/" + basename
@@ -410,5 +411,6 @@ mongo_install_rule = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
     },
     doc = "Install targets",
