--- Editeur/bureau.py.orig	Fri Dec 10 14:07:17 2004
+++ Editeur/bureau.py	Wed Apr 27 23:11:46 2005
@@ -565,11 +565,11 @@
           commande = self.appli.CONFIGURATION.exec_acrobat
           nom_fichier = cle_doc+".pdf"
           rep_fichier = cle_doc[0:2]
-          fichier = os.path.abspath(os.path.join(self.appli.CONFIGURATION.path_doc,rep_fichier,nom_fichier))
+          fichier = os.path.abspath(os.path.join(self.appli.CONFIGURATION.path_doc,nom_fichier))
           if os.name == 'nt':
               os.spawnv(os.P_NOWAIT,commande,(commande,fichier,))
           elif os.name == 'posix':
-              script ="#!/usr/bin/sh \n%s %s&" %(commande,fichier)
+              script ="#! /bin/sh \n%s %s&" %(commande,fichier)
               pid = os.system(script)
       except AttributeError:
           traceback.print_exc()
