--- build-support/asan_symbolize.py.orig	2025-02-23 00:58:26 UTC
+++ build-support/asan_symbolize.py
@@ -213,7 +213,7 @@ def SystemSymbolizerFactory(system, addr, binary):
 def SystemSymbolizerFactory(system, addr, binary):
   if system == 'Darwin':
     return DarwinSymbolizer(addr, binary)
-  elif system == 'Linux':
+  elif system == 'Linux' or system == 'FreeBSD':
     return Addr2LineSymbolizer(binary)
 
 
@@ -297,7 +297,7 @@ class SymbolizationLoop(object):
     # E.g. in Chrome several binaries may share a single .dSYM.
     self.binary_name_filter = binary_name_filter
     self.system = os.uname()[0]
-    if self.system in ['Linux', 'Darwin']:
+    if self.system in ['Linux', 'Darwin', 'FreeBSD']:
       self.llvm_symbolizer = LLVMSymbolizerFactory(self.system)
     else:
       raise Exception('Unknown system')
