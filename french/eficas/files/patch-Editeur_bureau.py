--- Editeur/bureau.py.orig	Tue Jan  3 18:02:45 2006
+++ Editeur/bureau.py	Mon Jan  9 22:26:41 2006
@@ -638,7 +638,7 @@
           if os.name == 'nt':
               os.spawnv(os.P_NOWAIT,commande,(commande,fichier,))
           elif os.name == 'posix':
-              script ="#!/usr/bin/sh \n%s %s&" %(commande,fichier)
+              script ="#! /bin/sh \n%s %s&" %(commande,fichier)
               pid = os.system(script)
       except AttributeError:
           traceback.print_exc()
