--- src/build_mozc.py.org	2010-05-29 11:06:11.353375791 +0900
+++ src/build_mozc.py	2010-05-29 11:49:27.698956304 +0900
@@ -67,7 +67,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and os.uname()[0] == 'FreeBSD'
 
 
 def GetGeneratorName():
@@ -356,7 +356,7 @@
                       default='Win32',
                       help='specify the target plaform: [Win32|x64]')
   # default Qt dir to support the current build procedure for Debian.
-  default_qtdir = '/usr/local/Trolltech/Qt-4.5.2'
+  default_qtdir = '@@LOCALBASE@@/lib/qt4/'
   if IsWindows():
     default_qtdir = None
   parser.add_option('--qtdir', dest='qtdir',
@@ -387,7 +387,7 @@
     (unused_gyp_file_name, target_name) = ParseTarget(target)
     target_names.append(target_name)
 
-  make_command = os.getenv('BUILD_COMMAND', 'make')
+  make_command = os.getenv('BUILD_COMMAND', 'gmake')
   # flags for building in Chrome OS chroot environment
   envvars = [
       'CFLAGS',
