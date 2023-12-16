--- setup/build.py.orig	2023-12-15 00:57:56 UTC
+++ setup/build.py
@@ -703,6 +703,7 @@ sip-file = {os.path.basename(sipf)!r}
 include-dirs = {ext.inc_dirs}
 qmake-QT = {ext.qt_modules}
 sip-file = {os.path.basename(sipf)!r}
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
