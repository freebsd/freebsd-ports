--- ./setup.py.orig	2014-04-23 23:17:14.713606058 +0200
+++ ./setup.py	2014-04-23 23:46:52.244901795 +0200
@@ -125,8 +125,9 @@
 else:
     base_path = os.path.join(sys.exec_prefix, "lib", "python" + sys.version[:3],
                              "site-packages","mnemosyne")
-    data_files = [("/usr/share/applications", ["mnemosyne.desktop"]),
-                  ("/usr/share/icons", ["pixmaps/mnemosyne.png"])]
+    data_files = [("share/applications", ["mnemosyne.desktop"]),
+                  ("share/icons", ["pixmaps/mnemosyne.png"])]
+
 # Translations.
 if sys.platform == "win32":
     for mo in [x for x in glob.glob(os.path.join("mo", "*")) \
@@ -240,4 +241,3 @@
       options = {"py2app": py2app_options, "py2exe": py2exe_options},
       app = py2app_app
 )
-
