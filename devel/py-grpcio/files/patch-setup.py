--- setup.py.orig	2017-10-26 17:03:10 UTC
+++ setup.py
@@ -37,13 +37,6 @@ PYTHON_STEM = os.path.join('src', 'pytho
 CORE_INCLUDE = ('include', '.',)
 BORINGSSL_INCLUDE = (os.path.join('third_party', 'boringssl', 'include'),)
 ZLIB_INCLUDE = (os.path.join('third_party', 'zlib'),)
-CARES_INCLUDE = (
-    os.path.join('third_party', 'cares'),
-    os.path.join('third_party', 'cares', 'cares'),)
-if 'linux' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_linux'),)
-if 'darwin' in sys.platform:
-  CARES_INCLUDE += (os.path.join('third_party', 'cares', 'config_darwin'),)
 README = os.path.join(PYTHON_STEM, 'README.rst')
 
 # Ensure we're in the proper directory whether or not we're being used by pip.
@@ -139,12 +132,9 @@ CYTHON_EXTENSION_MODULE_NAMES = ('grpc._
 CYTHON_HELPER_C_FILES = ()
 
 CORE_C_FILES = tuple(grpc_core_dependencies.CORE_SOURCE_FILES)
-if "win32" in sys.platform:
-  CORE_C_FILES = filter(lambda x: 'third_party/cares' not in x, CORE_C_FILES)
 
 EXTENSION_INCLUDE_DIRECTORIES = (
-    (PYTHON_STEM,) + CORE_INCLUDE + BORINGSSL_INCLUDE + ZLIB_INCLUDE +
-    CARES_INCLUDE)
+    (PYTHON_STEM,) + CORE_INCLUDE + BORINGSSL_INCLUDE + ZLIB_INCLUDE)
 
 EXTENSION_LIBRARIES = ()
 if "linux" in sys.platform:
