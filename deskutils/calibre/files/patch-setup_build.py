--- setup/build.py.orig	2025-04-18 03:14:01 UTC
+++ setup/build.py
@@ -701,6 +701,7 @@ sip-file = {os.path.basename(sipf)!r}
 include-dirs = {ext.inc_dirs}
 qmake-QT = {ext.qt_modules}
 sip-file = {os.path.basename(sipf)!r}
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
