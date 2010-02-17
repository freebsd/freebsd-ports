--- setup.py	2009-11-13 03:32:53.000000000 +0100
+++ setup.py	2009-11-13 03:35:25.000000000 +0100
@@ -52,9 +52,9 @@
   packages = ['PyRoom',],
   package_data = {'PyRoom':['interface.glade']},
   data_files = [
-    ('/usr/share/pyroom/themes', glob.glob('themes/*.theme')),
-    ('/usr/share/pyroom', ['pyroom.png']),
-    ('/usr/share/applications', ['pyroom.desktop'])
+    ('%%PREFIX%%/share/pyroom/themes', glob.glob('themes/*.theme')),
+    ('%%PREFIX%%/share/pyroom', ['pyroom.png']),
+    ('%%PREFIX%%/share/applications', ['pyroom.desktop'])
     ],
   scripts=['pyroom',],
   cmdclass={'install_data': InstallData},
