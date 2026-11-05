--- catalo/cataelem/Tools/base_objects.py.orig	2026-09-11 16:05:37 UTC
+++ catalo/cataelem/Tools/base_objects.py
@@ -1083,7 +1083,7 @@ def verif_identificateur(chaine, long):
         assert c in string.ascii_uppercase + string.digits + "_"
 
 
-RECMP_DECL = re.compile("(.*?)\[([0-9]+)\]")
+RECMP_DECL = re.compile(r"(.*?)\[([0-9]+)\]")
 
 
 def expandComponents(lcmp):
