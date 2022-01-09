--- setup.py.orig	2022-01-08 16:20:10 UTC
+++ setup.py
@@ -21,30 +21,6 @@ from subprocess import Popen
 DIR = os.path.abspath(os.path.dirname(__file__))
 # NOTE: If you are editing the array below then you probably also need
 # to change MANIFEST.in.
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
-    'third_party/md5/md5.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/char_traits.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/base64.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/language.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/memory_util.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/format.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/time.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/memory_resource.o',
-    'third_party/rapidyaml/rapidyaml/ext/c4core/src/c4/error.o',
-    'third_party/rapidyaml/rapidyaml/src/c4/yml/parse.o',
-    'third_party/rapidyaml/rapidyaml/src/c4/yml/preprocess.o',
-    'third_party/rapidyaml/rapidyaml/src/c4/yml/common.o',
-    'third_party/rapidyaml/rapidyaml/src/c4/yml/tree.o',
-]
 
 MODULE_SOURCES = ['python/_jsonnet.c']
 
@@ -60,19 +36,10 @@ def get_version():
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
-    include_dirs = ['include'],
+    libraries = ['jsonnet'],
     language='c++'
 )
 
@@ -83,9 +50,6 @@ setup(name='jsonnet',
       author='David Cunningham',
       author_email='dcunnin@google.com',
       version=get_version(),
-      cmdclass={
-          'build_ext': BuildJsonnetExt,
-      },
       ext_modules=[jsonnet_ext],
       test_suite="python._jsonnet_test",
 )
