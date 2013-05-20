--- rpython/translator/cli/sdk.py~	2012-06-11 12:24:05.000000000 +0200
+++ rpython/translator/cli/sdk.py	2012-06-11 12:24:42.000000000 +0200
@@ -47,7 +47,7 @@
 
 class MonoSDK(AbstractSDK):
     RUNTIME = ['mono']
-    ILASM = 'ilasm2'
+    ILASM = 'ilasm'
     CSC = 'gmcs'
     PEVERIFY = 'peverify' # it's not part of mono, but we get a meaningful skip message
 
