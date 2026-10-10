--- bazel/toolchains/cc/mongo_wasm/toolchain/wasi_repo.bzl.orig	2026-10-06 00:00:00 UTC
+++ bazel/toolchains/cc/mongo_wasm/toolchain/wasi_repo.bzl
@@ -45,7 +45,8 @@ def _normalize_arch(arch):
     return arch
 
 def _setup_wasi_deps(rctx):
-    os = _normalize_os(rctx.os.name)
+    host_os = rctx.os.name
+    os = _normalize_os(host_os)
     arch = _normalize_arch(rctx.os.arch)
     key = (os, arch)
 
@@ -75,6 +76,21 @@ def _setup_wasi_deps(rctx):
     # the toolchain config can use the same label on all platforms.
     exe = ".exe" if os == "windows" else ""
 
+    if host_os.startswith("freebsd"):
+        localbase = rctx.os.environ.get("LOCALBASE")
+        if not localbase:
+            localbase = "/usr/local"
+        llvm_bindir = localbase + "/bin"
+        native_tools = {
+            "wasm32-wasip2-clang": "clang22",
+            "wasm32-wasip2-clang++": "clang++22",
+            "llvm-ar": "llvm-ar22",
+        }
+        for tool, native_tool in native_tools.items():
+            target_arg = "" if tool == "llvm-ar" else " --target=wasm32-wasip2"
+            rctx.delete("bin/" + tool + exe)
+            rctx.file("bin/" + tool + exe, content = "#!/bin/sh\nexec \"{}/{}\"{} \"$@\"\n".format(llvm_bindir, native_tool, target_arg), executable = True)
+
     rctx.file(
         "BUILD.bazel",
         content = """
@@ -93,6 +108,7 @@ alias(name = "llvm-ar",               actual = "bin/llvm-ar{exe}")
         """.format(exe = exe),
     )
 
 setup_wasi_deps = repository_rule(
     implementation = _setup_wasi_deps,
+    environ = ["LOCALBASE"],
 )
