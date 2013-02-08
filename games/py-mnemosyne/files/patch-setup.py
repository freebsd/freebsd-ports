--- setup.py.orig	2012-07-28 07:11:07.000000000 +0200
+++ setup.py	2012-12-23 20:52:55.564991943 +0100
@@ -133,8 +133,7 @@
 else:
     base_path = os.path.join(sys.exec_prefix, "lib", "python" + sys.version[:3],
                              "site-packages","mnemosyne")
-    data_files = [("/usr/share/applications", ["mnemosyne.desktop"]),
-                  ("/usr/share/icons", ["pixmaps/mnemosyne.png"])]
+    data_files = []
 # Translations.
 if sys.platform == "win32":
     for mo in [x for x in glob.glob(os.path.join("mo", "*")) \
@@ -145,12 +144,6 @@
             [os.path.join(mo, "LC_MESSAGES", "mnemosyne.mo")]))
         data_files.append((os.path.join("share", "qt4", "translations"),
             glob.glob(os.path.join("mnemosyne", "pyqt_ui", "qm", '*'))))
-else:
-    for mo in [x for x in glob.glob(os.path.join("mo", "*"))
-               if os.path.isdir(x)]:
-        data_files.append((os.path.join(sys.exec_prefix, "share", "locale",
-            os.path.split(mo)[1], "LC_MESSAGES"),
-            [os.path.join(mo, "LC_MESSAGES", "mnemosyne.mo")]))
 
 pixmap_path = os.path.join(base_path, "pixmaps")
 util_path = os.path.join(base_path, "util")
@@ -250,4 +243,3 @@
       options = {"py2app": py2app_options, "py2exe": py2exe_options},
       app = py2app_app
 )
-
