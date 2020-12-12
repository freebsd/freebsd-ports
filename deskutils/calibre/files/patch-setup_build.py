--- setup/build.py.orig	2020-12-12 08:56:45 UTC
+++ setup/build.py
@@ -487,6 +487,7 @@ project-factory = "pyqtbuild:PyQtProject"
 
 [tool.sip.project]
 sip-files-dir = "."
+sip-module = "PyQt5.sip"
 
 [tool.sip.bindings.pictureflow]
 headers = {ext.headers}
@@ -495,6 +496,7 @@ exceptions = {needs_exceptions}
 include-dirs = {ext.inc_dirs}
 qmake-QT = ["widgets"]
 sip-file = "{os.path.basename(sipf)}"
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
@@ -523,6 +525,15 @@ sip-file = "{os.path.basename(sipf)}"
         cwd = os.getcwd()
         try:
             os.chdir(os.path.join(src_dir, 'build'))
+            if ext.needs_exceptions:
+                # bug in sip-build
+                for q in walk('.'):
+                    if os.path.basename(q) in ('Makefile',):
+                        with open(q, 'r+') as f:
+                            raw = f.read()
+                            raw = raw.replace('-fno-exceptions', '-fexceptions')
+                            f.seek(0), f.truncate()
+                            f.write(raw)
             self.check_call([self.env.make] + ([] if iswindows else ['-j%d'%(os.cpu_count() or 1)]))
             e = 'pyd' if iswindows else 'so'
             m = glob.glob(f'{ext.name}/{ext.name}.*{e}')
