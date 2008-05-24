--- src/sml/main/export.sml.orig	2000-01-14 03:02:38.000000000 +0100
+++ src/sml/main/export.sml	2007-10-27 18:26:21.000000000 +0200
@@ -81,7 +81,7 @@
 
 	fun asdlGen (name,args) =
 	  (run_it (name,args);OS.Process.success) handle e =>
-	    (Error.say ("Error: "^(exnMessage e)^"\n");
+	    (Error.say ("Error: "^(General.exnMessage e)^"\n");
 	     OS.Process.failure)
 
     end
