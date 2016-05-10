--- python/mainwindow.py.orig	2016-01-03 22:16:17 UTC
+++ python/mainwindow.py
@@ -63,8 +63,8 @@ class POLWeb(threading.Thread):
     def LastVersion(self):
         if(os.environ["POL_OS"] == "Mac"):
             fichier_online="version_mac"
-        elif(os.environ["POL_OS"] == "FreeBSD"):
-            fichier_online="version_freebsd"
+#        elif(os.environ["POL_OS"] == "FreeBSD"):
+#            fichier_online="version_freebsd"
         else:
             fichier_online="version2"
         return os.popen(os.environ["POL_WGET"]+' "'+os.environ["SITE"]+'/'+fichier_online+'.php?v='+os.environ["VERSION"]+'" -T 30 -O-','r').read()
