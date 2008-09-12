--- setup.py.orig	2008-08-23 08:05:54.000000000 -0800
+++ setup.py	2008-09-11 20:19:12.000000000 -0800
@@ -151,8 +151,7 @@
 else:
     base_path = os.path.join(sys.exec_prefix, "lib", "python"+sys.version[:3],
                              "site-packages","mnemosyne")
-    data_files = [('/usr/share/applications', ['mnemosyne.desktop']),
-                  ('/usr/share/icons', ['pixmaps/mnemosyne.png'])]
+    data_files = []
   
 pixmap_path = os.path.join(base_path, "pixmaps")
 util_path   = os.path.join(base_path, "util")
