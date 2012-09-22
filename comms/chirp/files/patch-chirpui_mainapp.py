--- chirpui/mainapp.py.orig	2012-09-16 03:13:31.000000000 -0500
+++ chirpui/mainapp.py	2012-09-16 03:14:17.000000000 -0500
@@ -1321,7 +1321,7 @@
         execpath = platform.get_platform().executable_path()
         path = os.path.abspath(os.path.join(execpath, "share", "chirp.png"))
         if not os.path.exists(path):
-            path = "/usr/share/pixmaps/chirp.png"
+            path = "%%LOCALBASE%%/share/pixmaps/chirp.png"
 
         if os.path.exists(path):
             self.set_icon_from_file(path)
