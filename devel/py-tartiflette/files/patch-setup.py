--- setup.py.orig	2021-11-15 11:04:50 UTC
+++ setup.py
@@ -42,7 +42,6 @@ class BuildExtCmd(build_ext):
 
 class BuildPyCmd(build_py):
     def run(self):
-        _build_libgraphqlparser()
         super().run()
 
 
@@ -52,6 +51,5 @@ class LibGraphQLParserExtension(Extension):
 
 
 setup(
-    cmdclass={"build_ext": BuildExtCmd, "build_py": BuildPyCmd},
-    ext_modules=[LibGraphQLParserExtension()],
+    cmdclass={"build_py": BuildPyCmd},
 )
