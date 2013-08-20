--- setup.py.orig	2013-08-20 10:38:37.000000000 +0800
+++ setup.py	2013-08-20 10:40:44.000000000 +0800
@@ -133,8 +133,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['blosc']
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['blosc','%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
@@ -160,13 +160,13 @@
     add_from_path("CPATH", default_header_dirs)
     add_from_path("C_INCLUDE_PATH", default_header_dirs)
     add_from_flags("CPPFLAGS", "-I", default_header_dirs)
-    default_header_dirs.extend(['/usr/include', '/usr/local/include'])
+    default_header_dirs.extend(['/usr/include', '/usr/local/include','%%LOCALBASE%%/include'])
 
     default_library_dirs = []
     add_from_flags("LDFLAGS", "-L", default_library_dirs)
     default_library_dirs.extend(
         os.path.join(_tree, _arch)
-        for _tree in ('/usr/local', '/sw', '/opt', '/opt/local', '/usr', '/')
+        for _tree in ('/usr/local', '/sw', '/opt', '/opt/local', '/usr', '/','%%LOCALBASE%%')
             for _arch in ('lib64', 'lib'))
     default_runtime_dirs = default_library_dirs
 
