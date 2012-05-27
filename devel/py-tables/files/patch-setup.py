--- setup.py.orig	2012-03-25 19:20:35.000000000 +0900
+++ setup.py	2012-03-25 19:22:53.000000000 +0900
@@ -96,8 +96,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['blosc']
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['blosc','%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
@@ -121,13 +121,12 @@
     add_from_path("CPATH", default_header_dirs)
     add_from_path("C_INCLUDE_PATH", default_header_dirs)
     add_from_flags("CPPFLAGS", "-I", default_header_dirs)
-    default_header_dirs.extend(['/usr/include', '/usr/local/include'])
-
+    default_header_dirs = ['/usr/include', '/usr/local/include','%%LOCALBASE%%/include']
     default_library_dirs = []
     add_from_flags("LDFLAGS", "-L", default_library_dirs)
     default_library_dirs.extend(
         os.path.join(_tree, _arch)
-        for _tree in ('/', '/usr', '/usr/local')
+	for _tree in ('/', '/usr', '/usr/local','%%LOCALBASE%%')
         for _arch in ('lib64', 'lib') )
     default_runtime_dirs = default_library_dirs
 
