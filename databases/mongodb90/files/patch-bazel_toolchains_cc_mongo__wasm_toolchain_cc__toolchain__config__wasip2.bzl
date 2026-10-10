--- bazel/toolchains/cc/mongo_wasm/toolchain/cc_toolchain_config_wasip2.bzl.orig	2026-10-06 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_wasm/toolchain/cc_toolchain_config_wasip2.bzl
@@ -82,6 +82,9 @@ def _wasi_cc_toolchain_config_wasip2_impl(ctx):
                 # find $(bazel info output_base) -name wasi-sysroot # BASH SCRIPT
                 # can be used to find it if we use a different repository rule later.
                 "--sysroot={}".format("external/_main~_repo_rules~wasi_sdk/share/wasi-sysroot"),
+                "-resource-dir=external/_main~_repo_rules~wasi_sdk/lib/clang/22",
+                "-isystem",
+                "external/_main~_repo_rules~wasi_sdk/share/wasi-sysroot/include/wasm32-wasip2/eh/c++/v1",
                 "-fno-common",
                 "-Oz",
                 "-ffunction-sections",
@@ -169,6 +172,8 @@ def _wasi_cc_toolchain_config_wasip2_impl(ctx):
             actions = all_link_actions,
             flag_groups = [flag_group(flags = [
                 "-Wl,--gc-sections",
+                "-fuse-ld=lld",
+                "-resource-dir=" + wasi_sdk + "/lib/clang/22",
                 "-Wl,--strip-debug",
                 # wasi-sdk 33 moved the exception-aware C++ runtime libs into eh/.
                 "-L" + wasi_sysroot + "/lib/wasm32-wasip2/eh",
@@ -250,7 +252,7 @@ def _wasi_cc_toolchain_config_wasip2_impl(ctx):
         abi_libc_version = "wasi",
         builtin_sysroot = wasi_sysroot,
         cxx_builtin_include_directories = [
-            wasi_sysroot + "/include/wasm32-wasip2/c++/v1",
+            wasi_sysroot + "/include/wasm32-wasip2/eh/c++/v1",
             wasi_sysroot + "/include/c++/v1",
             wasi_sdk + "/lib/clang/22/include",
             wasi_sysroot + "/include/wasm32-wasip2",
