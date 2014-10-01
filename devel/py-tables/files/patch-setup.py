--- setup.py.orig	2014-03-26 04:49:03.000000000 +0800
+++ setup.py	2014-10-01 21:25:20.000000000 +0800
@@ -25,6 +25,7 @@
 from distutils.dep_util import newer
 from distutils.util import convert_path
 from distutils.ccompiler import new_compiler
+from distutils.version import LooseVersion
 
 cmdclass = {}
 setuptools_kwargs = {}
@@ -122,21 +123,21 @@
 
 # Check if Cython is installed or not (requisite)
 try:
+    from Cython import __version__ as cython_version
     from Cython.Distutils import build_ext
-    from Cython.Compiler.Main import Version
     cmdclass['build_ext'] = build_ext
 except ImportError:
     exit_with_error(
         "You need %(pkgname)s %(pkgver)s or greater to compile PyTables!"
         % {'pkgname': 'Cython', 'pkgver': min_cython_version})
 
-if Version.version < min_cython_version:
+if LooseVersion(cython_version) < min_cython_version:
     exit_with_error(
-        "At least Cython %s is needed so as to generate extensions!"
-        % (min_cython_version))
+        "You need %(pkgname)s %(pkgver)s or greater to run PyTables!"
+        % {'pkgname': 'Cython', 'pkgver': min_cython_version})
 else:
     print("* Found %(pkgname)s %(pkgver)s package installed."
-          % {'pkgname': 'Cython', 'pkgver': Version.version})
+          % {'pkgname': 'Cython', 'pkgver': cython_version})
 
 VERSION = open('VERSION').read().strip()
 
@@ -145,8 +146,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['c-blosc/hdf5']
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['c-blosc/hdf5','%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
@@ -168,7 +169,7 @@
             dirs.append(flag[len(flag_key):])
 
 if os.name == 'posix':
-    prefixes = ('/usr/local', '/sw', '/opt', '/opt/local', '/usr', '/')
+    prefixes = ('/usr/local', '/sw', '/opt', '/opt/local', '/usr', '/','%%LOCALBASE%%')
 
     default_header_dirs = []
     add_from_path("CPATH", default_header_dirs)
