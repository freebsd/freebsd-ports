--- setup.py.orig	2007-12-27 10:09:54.000000000 -0900
+++ setup.py	2008-01-14 08:59:26.000000000 -0900
@@ -147,8 +147,8 @@
 else:
     base_path = os.path.join(sys.exec_prefix, "lib", "python"+sys.version[:3],
                              "site-packages","mnemosyne")
-    data_files = [('/usr/share/applications', ['mnemosyne.desktop']),
-                  ('/usr/share/icons', ['pixmaps/mnemosyne.png'])]
+    data_files = [('/usr/local/share/applications', ['mnemosyne.desktop']),
+                  ('/usr/local/share/icons', ['pixmaps/mnemosyne.png'])]
   
 pixmap_path = os.path.join(base_path, "pixmaps")
 util_path   = os.path.join(base_path, "util")
