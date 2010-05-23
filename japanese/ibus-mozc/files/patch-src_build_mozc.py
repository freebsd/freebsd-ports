--- src/build_mozc.py.org	2010-05-23 14:03:31.479966714 +0900
+++ src/build_mozc.py	2010-05-23 13:58:56.143361084 +0900
@@ -64,9 +64,9 @@
   return os.name == 'posix' and os.uname()[0] == 'Darwin'
 
 
-def IsLinux():
-  """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+def IsFreeBSD():
+  """Returns true if the platform is FreeBSD."""
+  return os.name == 'posix' and os.uname()[0] == 'FreeBSD'
 
 
 def GetGeneratorName():
@@ -129,7 +129,7 @@
     gyp_file_names.extend(glob.glob('%s/win32/*/*.gyp' % SRC_DIR))
     gyp_file_names.extend(glob.glob('third_party/breakpad/*.gyp'))
     gyp_file_names.append('third_party/mozc/sandbox/sandbox.gyp')
-  elif IsLinux():
+  elif IsFreeBSD():
     gyp_file_names.extend(glob.glob('%s/unix/*/*.gyp' % SRC_DIR))
     # Add ibus.gyp if ibus is isntalled.
     # Ubuntu 8.04 (Hardy) does not contain ibus package.
@@ -192,7 +192,7 @@
     elif IsMac():
       directory_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                     '*.xcodeproj')))
-    elif IsLinux():
+    elif IsFreeBSD():
       file_names.extend(glob.glob(os.path.join(gyp_directory_name,
                                                '*.target.mk')))
   file_names.append('%s/mozc_version.txt' % SRC_DIR)
@@ -201,7 +201,7 @@
   directory_names.append('mozc_build_tools')
   if IsMac():
     directory_names.append('xcodebuild')
-  elif IsLinux():
+  elif IsFreeBSD():
     file_names.append('Makefile')
     directory_names.append('out')
   elif IsWindows():
@@ -374,14 +374,14 @@
   return (gyp_file_name, target_name)
 
 
-def BuildOnLinux(options, targets):
-  """Build the targets on Linux."""
+def BuildOnFreeBSD(options, targets):
+  """Build the targets on FreeBSD."""
   target_names = []
   for target in targets:
     (unused_gyp_file_name, target_name) = ParseTarget(target)
     target_names.append(target_name)
 
-  make_command = os.getenv('BUILD_COMMAND', 'make')
+  make_command = os.getenv('BUILD_COMMAND', 'gmake')
   # flags for building in Chrome OS chroot environment
   envvars = [
       'CFLAGS',
@@ -530,8 +530,8 @@
 
   if IsMac():
     BuildOnMac(options, targets, original_directory_name)
-  elif IsLinux():
-    BuildOnLinux(options, targets)
+  elif IsFreeBSD():
+    BuildOnFreeBSD(options, targets)
   elif IsWindows():
     BuildOnWindows(options, targets, original_directory_name)
   else:
