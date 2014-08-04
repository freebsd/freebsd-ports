--- Lib/distutils/command/build_ext.py.orig	2014-07-20 11:51:54.000000000 +0200
+++ Lib/distutils/command/build_ext.py	2014-07-20 11:52:52.000000000 +0200
@@ -236,12 +236,9 @@
                 # building python standard extensions
                 self.library_dirs.append('.')
 
-        # for extensions under Linux or Solaris with a shared Python library,
         # Python's library directory must be appended to library_dirs
-        sysconfig.get_config_var('Py_ENABLE_SHARED')
-        if ((sys.platform.startswith('linux') or sys.platform.startswith('gnu')
-             or sys.platform.startswith('sunos'))
-            and sysconfig.get_config_var('Py_ENABLE_SHARED')):
+        # See Issues: #1600860, #4366
+        if (sysconfig.get_config_var('Py_ENABLE_SHARED')):
             if sys.executable.startswith(os.path.join(sys.exec_prefix, "bin")):
                 # building third party extensions
                 self.library_dirs.append(sysconfig.get_config_var('LIBDIR'))
