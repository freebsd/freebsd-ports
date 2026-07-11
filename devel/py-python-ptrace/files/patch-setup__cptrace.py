--- setup_cptrace.py.orig	2026-07-11 13:49:49 UTC
+++ setup_cptrace.py
@@ -17,7 +17,8 @@ def main():
 
 
 def main():
-    from imp import load_source
+    import importlib.machinery
+    import importlib.util
     from os import path
     from sys import argv
 
@@ -29,7 +30,13 @@ def main():
 
     cptrace_ext = Extension('cptrace', sources=SOURCES)
 
-    cptrace = load_source("version", path.join("cptrace", "version.py"))
+    filepath = path.join("cptrace", "version.py")
+    loader = importlib.machinery.SourceFileLoader("version", filepath)
+    spec = importlib.util.spec_from_file_location(
+             "version", filepath, loader=loader)
+    module = importlib.util.module_from_spec(spec)
+    loader.exec_module(module)
+    cptrace = module
 
     install_options = {
         "name": cptrace.PACKAGE,
