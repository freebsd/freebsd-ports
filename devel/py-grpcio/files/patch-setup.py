--- setup.py.orig	2018-04-13 19:56:08 UTC
+++ setup.py
@@ -37,17 +37,6 @@ PYTHON_STEM = os.path.join('src', 'pytho
 CORE_INCLUDE = ('include', '.',)
 BORINGSSL_INCLUDE = (os.path.join('third_party', 'boringssl', 'include'),)
 ZLIB_INCLUDE = (os.path.join('third_party', 'zlib'),)
-CARES_INCLUDE = (
-    os.path.join('third_party', 'cares'),
-    os.path.join('third_party', 'cares', 'cares'),)
-if 'darwin' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_darwin'),)
-if 'freebsd' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_freebsd'),)
-if 'linux' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_linux'),)
-if 'openbsd' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_openbsd'),)
 ADDRESS_SORTING_INCLUDE = (os.path.join('third_party', 'address_sorting', 'include'),)
 README = os.path.join(PYTHON_STEM, 'README.rst')
 
@@ -145,12 +134,10 @@ CYTHON_EXTENSION_MODULE_NAMES = ('grpc._
 CYTHON_HELPER_C_FILES = ()
 
 CORE_C_FILES = tuple(grpc_core_dependencies.CORE_SOURCE_FILES)
-if "win32" in sys.platform:
-  CORE_C_FILES = filter(lambda x: 'third_party/cares' not in x, CORE_C_FILES)
 
 EXTENSION_INCLUDE_DIRECTORIES = (
     (PYTHON_STEM,) + CORE_INCLUDE + BORINGSSL_INCLUDE + ZLIB_INCLUDE +
-    CARES_INCLUDE + ADDRESS_SORTING_INCLUDE)
+    ADDRESS_SORTING_INCLUDE)
 
 EXTENSION_LIBRARIES = ()
 if "linux" in sys.platform:
