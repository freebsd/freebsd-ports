--- setup.py.orig	2010-03-23 00:07:56.000000000 -0700
+++ setup.py	2010-08-15 21:33:21.000000000 -0700
@@ -30,12 +30,6 @@
 class install(installbase):
     def run(self):
         installbase.run(self)
-        self._write_file("tegaki-recognize.in", 
-                         os.path.join("share", "menu"),
-                         0644)
-        self._write_file("tegaki-recognize.desktop.in", 
-                         os.path.join("share", "applications"),
-                         0644)
 
     def _write_file(self, filename, folder, mode):
         txt = load_file(filename)
