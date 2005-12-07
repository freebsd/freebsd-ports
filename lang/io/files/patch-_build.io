--- _build.io.orig	Wed Dec  7 10:28:39 2005
+++ _build.io	Wed Dec  7 10:30:02 2005
@@ -74,7 +74,7 @@
     )
     
     systemCall := method(s,
-		if(trySystemCall(s) == 256, System exit)    
+		if(trySystemCall(s) == 256, System exit(1))    
     )
 
     trySystemCall := method(s,
