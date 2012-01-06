--- taskcoachlib/powermgt/idle.py.orig	2011-11-27 18:30:04.000000000 +0800
+++ taskcoachlib/powermgt/idle.py	2012-01-06 10:26:51.000000000 +0800
@@ -21,9 +21,9 @@
 
 
 #==============================================================================
-# Linux
+# Linux / FreeBSD
 
-if sys.platform == 'linux2':
+if (sys.platform == 'linux2') or (sys.platform.startswith('freebsd')):
     class XScreenSaverInfo(Structure):
         _fields_ = [('window', c_ulong),
                     ('state', c_int),
