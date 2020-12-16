--- setup/build.py.orig	2020-12-12 08:56:45 UTC
+++ setup/build.py
@@ -495,6 +495,7 @@ exceptions = {needs_exceptions}
 include-dirs = {ext.inc_dirs}
 qmake-QT = ["widgets"]
 sip-file = "{os.path.basename(sipf)}"
+tags = ["WS_X11"]
 ''')
         shutil.copy2(sipf, src_dir)
 
