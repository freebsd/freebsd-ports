--- setup.py.orig	2010-07-06 11:11:43.000000000 +0800
+++ setup.py	2010-07-06 11:13:13.000000000 +0800
@@ -83,8 +83,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['blosc']
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['blosc','%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
@@ -93,10 +93,10 @@
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
 
