--- setup.py.orig	Fri May 14 15:17:43 2004
+++ setup.py	Sun Nov  7 01:02:10 2004
@@ -199,7 +199,7 @@
                 self.compiler.set_executable("linker_so",
                         cxx + ["-shared"])
             elif build: # fix for 2.3, only if we are making C++ modules
-                self.compiler.compiler_so = self.compiler.compiler_cxx
+                self.compiler.compiler_so = self.compiler.compiler_cxx + ["-fPIC"]
         else:
             self.compiler.compiler_so = self._original_compiler_so
 
