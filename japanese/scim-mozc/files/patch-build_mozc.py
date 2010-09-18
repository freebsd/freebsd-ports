--- build_mozc.py.org	2010-09-18 12:36:34.298723774 +0900
+++ build_mozc.py	2010-09-18 12:43:00.635215143 +0900
@@ -69,7 +69,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
@@ -576,6 +576,8 @@
 
   # default Qt dir to support the current build procedure for Debian.
   default_qtdir = '/usr/local/Trolltech/Qt-4.6.3'
+  if os.uname()[0] == 'FreeBSD':
+    default_qtdir = '@@LOCALBASE@@/lib/qt4'
   if IsWindows():
     default_qtdir = None
   parser.add_option('--qtdir', dest='qtdir',
@@ -627,6 +629,8 @@
     target_names.append(target_name)
 
   make_command = os.getenv('BUILD_COMMAND', 'make')
+  if os.uname()[0] == 'FreeBSD':
+    make_command = os.getenv('BUILD_COMMAND', 'gmake')
   # flags for building in Chrome OS chroot environment
   envvars = [
       'CFLAGS',
