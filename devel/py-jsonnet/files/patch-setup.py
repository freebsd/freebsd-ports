--- setup.py.orig	2020-11-22 14:19:41 UTC
+++ setup.py
@@ -19,18 +19,6 @@ from setuptools.command.build_ext import build_ext as 
 from subprocess import Popen
 
 DIR = os.path.abspath(os.path.dirname(__file__))
-LIB_OBJECTS = [
-    'core/desugarer.o',
-    'core/formatter.o',
-    'core/libjsonnet.o',
-    'core/lexer.o',
-    'core/parser.o',
-    'core/pass.o',
-    'core/static_analysis.o',
-    'core/string_utils.o',
-    'core/vm.o',
-    'third_party/md5/md5.o'
-]
 
 MODULE_SOURCES = ['python/_jsonnet.c']
 
@@ -46,19 +34,10 @@ def get_version():
                     v_code = v_code[1:]
                 return v_code
 
-class BuildJsonnetExt(BuildExt):
-    def run(self):
-        p = Popen(['make'] + LIB_OBJECTS, cwd=DIR)
-        p.wait()
-        if p.returncode != 0:
-            raise Exception('Could not build %s' % (', '.join(LIB_OBJECTS)))
-        BuildExt.run(self)
-
 jsonnet_ext = Extension(
     '_jsonnet',
     sources=MODULE_SOURCES,
-    extra_objects=LIB_OBJECTS,
-    include_dirs = ['include', 'third_party/md5', 'third_party/json'],
+    libraries = ['jsonnet'],
     language='c++'
 )
 
@@ -68,9 +47,6 @@ setup(name='jsonnet',
       author='David Cunningham',
       author_email='dcunnin@google.com',
       version=get_version(),
-      cmdclass={
-          'build_ext': BuildJsonnetExt,
-      },
       ext_modules=[jsonnet_ext],
       test_suite="python._jsonnet_test",
 )
