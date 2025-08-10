--- setup/build.py.orig	2025-08-08 02:10:36 UTC
+++ setup/build.py
@@ -446,6 +446,8 @@ class Build(Command):
                 continue
             if not is_ext_allowed(self.compiling_for, ext):
                 continue
+            if ext.name == 'piper':
+                continue
             if ext.error:
                 if ext.optional:
                     self.warn(ext.error)
@@ -703,6 +705,7 @@ sip-file = {os.path.basename(sipf)!r}
 include-dirs = {ext.inc_dirs}
 qmake-QT = {ext.qt_modules}
 sip-file = {os.path.basename(sipf)!r}
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
