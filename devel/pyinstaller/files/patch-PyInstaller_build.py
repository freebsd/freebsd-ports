--- PyInstaller/build.py.orig	2013-09-15 20:27:11 UTC
+++ PyInstaller/build.py
@@ -1411,8 +1411,17 @@ class COLLECT(Target):
                                  upx=(self.upx_binaries and (is_win or is_cygwin)), 
                                  dist_nm=inm)
             if typ != 'DEPENDENCY':
-                shutil.copy2(fnm, tofnm)
-            if typ in ('EXTENSION', 'BINARY'):
+                def copy_noschg(src, dst):
+                    """ copy access/modification times and user flags only to
+                        allow operation under regular user e.g. on FreeBSD,
+                        where /lib/libc.so.* by default has stat.SF_IMMUTABLE
+                        flag set (which is super-user only)"""
+                    shutil.copyfile(src, dst)
+                    sb = os.stat(src)
+                    os.utime(dst, (sb.st_atime, sb.st_mtime))
+                    os.chflags(dst, sb.st_flags & 0x0000ffff)	# UF_SETTABLE
+                copy_noschg(fnm, tofnm)
+            if typ in ('EXTENSION', 'BINARY', 'EXECUTABLE'):
                 os.chmod(tofnm, 0755)
         _save_data(self.out,
                  (self.name, self.strip_binaries, self.upx_binaries, self.toc))
