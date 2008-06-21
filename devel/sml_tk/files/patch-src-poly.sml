--- src/poly.sml.orig	Sun Jan 13 18:42:52 2008
+++ src/poly.sml	Sun Jan 13 18:42:35 2008
@@ -20,7 +20,7 @@
     (* from Isabelle --- to be used in Makefiles *)
     fun exportML{init:unit->unit, 
                  banner:string, 
-                 imagefile:string} = (PolyML.commit();())
+                 imagefile:string} = (PolyML.SaveState.saveState imagefile)
         (* runs only very rudimentarily . . . *)
 
     fun setPrintDepth x = ();
