--- setup.py.orig	2009-06-18 17:57:21.000000000 +0800
+++ setup.py	2009-06-18 18:02:43.000000000 +0800
@@ -81,8 +81,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = []
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
@@ -91,10 +91,10 @@
 default_runtime_dirs = None
 
 if os.name == 'posix':
-    default_header_dirs = ['/usr/include', '/usr/local/include']
+    default_header_dirs = ['/usr/include', '/usr/local/include','%%LOCALBASE%%/include']
     default_library_dirs = [
         os.path.join(_tree, _arch)
-        for _tree in ('/', '/usr', '/usr/local')
+        for _tree in ('/', '/usr', '/usr/local','%%LOCALBASE%%')
         for _arch in ('lib64', 'lib') ]
     default_runtime_dirs = default_library_dirs
 
