--- capstone/__init__.py.orig	2026-09-18 17:56:39 UTC
+++ capstone/__init__.py
@@ -401,7 +401,9 @@ _path_list = [os.getenv('LIBCAPSTONE_PATH', None),
               join(split(__file__)[0], 'lib'),
               '',
               sysconfig.get_path('platlib'),
-              "/usr/local/lib/" if sys.platform == 'darwin' else '/usr/lib64']
+              "%%LOCALBASE%%/lib/" if sys.platform == 'darwin'
+                                   or sys.platform.startswith('freebsd')
+                                else '/usr/lib64']
 
 for _path in _path_list:
     if _path is None: continue
