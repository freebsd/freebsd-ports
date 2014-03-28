--- InterfaceQT4/typeNode.py.orig	2013-12-12 11:25:35.000000000 +0100
+++ InterfaceQT4/typeNode.py	2014-01-16 11:08:00.000000000 +0100
@@ -182,7 +182,7 @@
         if os.name == 'nt':
            os.spawnv(os.P_NOWAIT,commande,(commande,fichier,))
         elif os.name == 'posix':
-            script ="#!/usr/bin/sh \n%s %s&" %(commande,fichier)
+            script ="#! /bin/sh \n%s %s&" %(commande,fichier)
             pid = os.system(script)
 
     def addParametersApres(self):
