--- build_mozc.py.org	2010-06-17 15:59:08.104932923 +0900
+++ build_mozc.py	2010-06-26 14:43:42.504687128 +0900
@@ -68,7 +68,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and os.uname()[0] == 'FreeBSD'
 
 
 def GetGeneratorName():
@@ -403,7 +403,7 @@
     (unused_gyp_file_name, target_name) = ParseTarget(target)
     target_names.append(target_name)
 
-  make_command = os.getenv('BUILD_COMMAND', 'make')
+  make_command = os.getenv('BUILD_COMMAND', 'gmake')
   # flags for building in Chrome OS chroot environment
   envvars = [
       'CFLAGS',
