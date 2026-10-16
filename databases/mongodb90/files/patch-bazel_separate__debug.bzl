--- bazel/separate_debug.bzl.orig	2026-10-14 17:59:44 UTC
+++ bazel/separate_debug.bzl
@@ -633,6 +633,7 @@ def extract_debuginfo_impl(ctx):
     linux_constraint = ctx.attr._linux_constraint[platform_common.ConstraintValueInfo]
     macos_constraint = ctx.attr._macos_constraint[platform_common.ConstraintValueInfo]
     windows_constraint = ctx.attr._windows_constraint[platform_common.ConstraintValueInfo]
+    freebsd_constraint = ctx.attr._freebsd_constraint[platform_common.ConstraintValueInfo]
     wasi_constraint = ctx.attr._wasi_constraint[platform_common.ConstraintValueInfo]
 
     dynamic_libraries = 0
@@ -647,7 +648,7 @@ def extract_debuginfo_impl(ctx):
     elif ctx.attr.type == "library" and dynamic_libraries == 0 and ctx.attr.cc_shared_library == None and ctx.attr.skip_archive == True:
         # On dynamic builds we skip separating debug if there are no dynamic libraries
         return_info = [ctx.attr.binary_with_debug[CcInfo]]
-    elif ctx.target_platform_has_constraint(linux_constraint):
+    elif ctx.target_platform_has_constraint(linux_constraint) or ctx.target_platform_has_constraint(freebsd_constraint):
         return_info = linux_extraction(ctx, cc_toolchain, inputs)
     elif ctx.target_platform_has_constraint(macos_constraint):
         return_info = macos_extraction(ctx, cc_toolchain, inputs)
@@ -695,6 +696,7 @@ extract_debuginfo = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
         "_wasi_constraint": attr.label(default = "@platforms//cpu:wasm32"),
     },
     doc = "Extract debuginfo into a separate file",
@@ -729,6 +731,7 @@ extract_debuginfo_binary = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
         "_wasi_constraint": attr.label(default = "@platforms//cpu:wasm32"),
     },
     doc = "Extract debuginfo into a separate file",
@@ -763,6 +766,7 @@ extract_debuginfo_test = rule(
         "_linux_constraint": attr.label(default = "@platforms//os:linux"),
         "_macos_constraint": attr.label(default = "@platforms//os:macos"),
         "_windows_constraint": attr.label(default = "@platforms//os:windows"),
+        "_freebsd_constraint": attr.label(default = "@platforms//os:freebsd"),
         "_wasi_constraint": attr.label(default = "@platforms//cpu:wasm32"),
         # Required for `bazel coverage` to invoke the C++ coverage collection
         # script (collect_cc_coverage.sh) and merge profraw -> _cc_coverage.dat,
