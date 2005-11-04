--- _build.io.orig	Fri Nov  4 21:30:40 2005
+++ _build.io	Fri Nov  4 21:31:56 2005
@@ -70,7 +70,7 @@
     )
     
     systemCall := method(s,
-	if (trySystemCall(s) == 256, System exit)    
+	if (trySystemCall(s) == 256, System exit(1))    
     )
 
     trySystemCall := method(s,
@@ -448,7 +448,7 @@
 Directory setCurrentWorkingDirectory(launchPath)
 if(args at(0), Project clone doString(args join(" ")), Project clone build)
 
-System exit(1)
+System exit(0)
 
 
 default := method(
