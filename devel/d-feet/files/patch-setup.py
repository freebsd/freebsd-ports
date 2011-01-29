--- setup.py.orig	2010-09-11 16:27:38.000000000 +0800
+++ setup.py	2010-09-11 17:54:40.000000000 +0800
@@ -58,6 +58,7 @@
     platforms='linux',
     scripts=['d-feet'],
     packages=['dfeet', 'dfeet/_ui'],
+    zip_safe=False,
     data_files=[
         ('share/dfeet', glob.glob("ui/*.ui")),
         ('share/icons/hicolor/16x16/apps', glob.glob("icons/16x16/*.png")),
