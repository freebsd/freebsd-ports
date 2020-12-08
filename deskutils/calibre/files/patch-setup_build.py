--- setup/build.py.orig	2020-10-10 16:20:32 UTC
+++ setup/build.py
@@ -496,6 +496,7 @@ exceptions = {needs_exceptions}
 include-dirs = {ext.inc_dirs}
 qmake-QT = ["widgets"]
 sip-file = "{os.path.basename(sipf)}"
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
