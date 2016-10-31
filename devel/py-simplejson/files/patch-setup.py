--- setup.py.orig	2016-10-21 07:55:07 UTC
+++ setup.py
@@ -64,25 +64,8 @@ class ve_build_ext(build_ext):
             raise BuildFailed()
 
 
-class TestCommand(Command):
-    user_options = []
-
-    def initialize_options(self):
-        pass
-
-    def finalize_options(self):
-        pass
-
-    def run(self):
-        import sys, subprocess
-        raise SystemExit(
-            subprocess.call([sys.executable,
-                             # Turn on deprecation warnings
-                             '-Wd',
-                             'simplejson/tests/__init__.py']))
-
 def run_setup(with_binary):
-    cmdclass = dict(test=TestCommand)
+    cmdclass = dict()
     if with_binary:
         kw = dict(
             ext_modules = [
@@ -105,6 +88,7 @@ def run_setup(with_binary):
         license="MIT License",
         packages=['simplejson', 'simplejson.tests'],
         platforms=['any'],
+        test_suite='simplejson.tests',
         **kw)
 
 try:
