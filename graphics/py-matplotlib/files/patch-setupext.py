--- setupext.py.orig	Fri Jul  9 19:51:16 2004
+++ setupext.py	Wed Aug  4 10:57:03 2004
@@ -37,6 +37,7 @@
     'linux'  : ['/usr/local', '/usr',],
     'darwin' : [os.getenv('MPLIB_BASE') or '/usr/local', '/usr', '/sw'],
     'freebsd4' : [os.getenv('MBLIB_BASE') or '/usr/local', '/usr'],
+    'freebsd5' : [os.getenv('MBLIB_BASE') or '/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
 }
 
@@ -220,7 +221,7 @@
         else:
             module.include_dirs.extend([o.tcl_inc, o.tk_inc])
             module.library_dirs.extend([o.tcl_lib, o.tk_lib])
-            module.libraries.extend(['tk'+o.tkv, 'tcl'+o.tkv])
+            module.libraries.extend(['tk84', 'tcl84'])
 
 
 def add_windowing_flags(module):
