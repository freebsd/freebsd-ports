--- setup/install.py.orig	2009-10-10 06:15:00.000000000 +0400
+++ setup/install.py	2009-10-12 14:23:51.000000000 +0400
@@ -8,7 +8,7 @@
 
 import sys, os, textwrap, subprocess, shutil, tempfile, atexit, stat
 
-from setup import Command, islinux, basenames, modules, functions, \
+from setup import Command, islinux, isfreebsd, basenames, modules, functions, \
         __appname__, __version__
 
 HEADER = '''\
@@ -115,7 +115,7 @@
 
 
     def pre_sub_commands(self, opts):
-        if not islinux:
+        if not (islinux or isfreebsd):
             self.info('\nSetting up a source based development environment is only '
                     'supported on linux. On other platforms, see the User Manual'
                     ' for help with setting up a development environment.')
@@ -143,9 +143,9 @@
             self.warn('Failed to compile mount helper. Auto mounting of',
                 ' devices will not work')
 
-        if os.geteuid() != 0:
-            return self.warn('Must be run as root to compile mount helper. Auto '
-                    'mounting of devices will not work.')
+#        if os.geteuid() != 0:
+#            return self.warn('Must be run as root to compile mount helper. Auto '
+#                    'mounting of devices will not work.')
         src = os.path.join(self.SRC, 'calibre', 'devices', 'linux_mount_helper.c')
         dest = os.path.join(self.staging_bindir, 'calibre-mount-helper')
         self.info('Installing mount helper to '+ dest)
@@ -153,9 +153,9 @@
         ret = p.wait()
         if ret != 0:
             return warn()
-        os.chown(dest, 0, 0)
-        os.chmod(dest, stat.S_ISUID|stat.S_ISGID|stat.S_IRUSR|stat.S_IWUSR|\
-                stat.S_IXUSR|stat.S_IXGRP|stat.S_IXOTH)
+#        os.chown(dest, 0, 0)
+#        os.chmod(dest, stat.S_ISUID|stat.S_ISGID|stat.S_IRUSR|stat.S_IWUSR|\
+#                stat.S_IXUSR|stat.S_IXGRP|stat.S_IXOTH)
         self.manifest.append(dest)
         return dest
 
