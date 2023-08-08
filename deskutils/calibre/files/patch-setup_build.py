--- setup/build.py.orig	2023-02-03 02:11:49 UTC
+++ setup/build.py
@@ -682,6 +682,7 @@ sip-file = "{os.path.basename(sipf)}"
 include-dirs = {ext.inc_dirs}
 qmake-QT = {ext.qt_modules}
 sip-file = "{os.path.basename(sipf)}"
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
