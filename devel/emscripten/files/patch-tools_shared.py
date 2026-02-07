--- tools/shared.py.orig	2024-08-20 03:02:04 UTC
+++ tools/shared.py
@@ -542,7 +542,7 @@ def build_llvm_tool_path(tool):
 # the version to the binaries, cope with that
 def build_llvm_tool_path(tool):
   if config.LLVM_ADD_VERSION:
-    return os.path.join(config.LLVM_ROOT, tool + "-" + config.LLVM_ADD_VERSION)
+    return os.path.join(config.LLVM_ROOT, tool + config.LLVM_ADD_VERSION)
   else:
     return os.path.join(config.LLVM_ROOT, tool)
 
@@ -551,7 +551,7 @@ def build_clang_tool_path(tool):
 # the version to the binaries, cope with that
 def build_clang_tool_path(tool):
   if config.CLANG_ADD_VERSION:
-    return os.path.join(config.LLVM_ROOT, tool + "-" + config.CLANG_ADD_VERSION)
+    return os.path.join(config.LLVM_ROOT, tool + config.CLANG_ADD_VERSION)
   else:
     return os.path.join(config.LLVM_ROOT, tool)
 
