Fix the compile with vala 0.24. Patch from upstream


--- Steadyflow/Services.vala.orig	2014-10-01 16:34:37.909464669 +0200
+++ Steadyflow/Services.vala	2014-10-01 16:34:55.297464318 +0200
@@ -61,7 +61,7 @@
 				 "information to the developer:\n\nError Code %d:\n\n%s").printf (e.code, message));
 			
 		md.run ();
-		exit(1);
+		GLib.Process.exit(1);
 	}
 }
 
