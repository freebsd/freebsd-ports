--- bibpyt/Execution/E_SUPERV.py.orig	Wed Oct 22 07:17:43 2003
+++ bibpyt/Execution/E_SUPERV.py	Sat Nov 15 14:22:56 2003
@@ -192,7 +192,7 @@
       if j.par_lot == 'NON':
          print "FIN EXECUTION"
          if j.fico!=None :
-            os.system('cat ./fort.15 ./ficode >> ./fort.15')
+            os.system('cat ./ficode >> ./fort.15')
          return ier
 
       # Verification de la validite du jeu de commande
@@ -272,7 +272,7 @@
             return 1   
       except EOFError:
          if j.fico!=None :
-            os.system('cat ./fort.15 ./ficode >> ./fort.15')
+            os.system('cat ./ficode >> ./fort.15')
          return 0
       except :
          self.MESSAGE("ERREUR INOPINEE - INTERRUPTION")
@@ -296,7 +296,7 @@
             print ">> JDC.py : FIN RAPPORT"
 
          if j.fico!=None :
-            os.system('cat ./fort.15 ./ficode >> ./fort.15')
+            os.system('cat ./ficode >> ./fort.15')
 
          return ier
 
