--- Robot/fitter.c.orig	2009-04-11 22:10:28.000000000 +0200
+++ Robot/fitter.c	2009-04-11 22:10:41.000000000 +0200
@@ -486,7 +486,7 @@
 		getamod_(&i, &length, temp_name);
 		strncpy(model_name, temp_name, length);
 
-		model_name[length] = (char) NULL;
+		model_name[length] = 0;
 
 
 		add_named_model(model_name);
