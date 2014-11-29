--- bbfreeze/freezer.py.orig	2013-11-08 07:20:06 UTC
+++ bbfreeze/freezer.py
@@ -1,4 +1,4 @@
-import os
+import os, stat
 import sys
 import re
 import time
@@ -791,16 +791,24 @@ if __name__ == '__main__':
         os.environ['S'] = p
         os.system('strip $S')
 
+    def copy_noschg(self, src, dst):
+        """ copy access/modification times and user flags only to
+            allow operation under regular user e.g. on FreeBSD,
+            where /lib/libc.so.* by default has stat.SF_IMMUTABLE
+            flag set (which is super-user only)"""
+        shutil.copyfile(src, dst)
+        sb = os.stat(src)
+        os.utime(dst, (sb.st_atime, sb.st_mtime))
+        os.chflags(dst, sb.st_flags & 0x0000ffff)	# UF_SETTABLE
+
     def _handle_Executable(self, m):
         dst = os.path.join(self.distdir, os.path.basename(m.filename))
-        shutil.copy2(m.filename, dst)
-        os.chmod(dst, 0755)
+        self.copy_noschg(m.filename, dst)
         self.adaptBinary(dst)
 
     def _handle_SharedLibrary(self, m):
         dst = os.path.join(self.distdir, os.path.basename(m.filename))
-        shutil.copy2(m.filename, dst)
-        os.chmod(dst, 0755)
+        self.copy_noschg(m.filename, dst)
         self.adaptBinary(dst)
 
     def showxref(self):
