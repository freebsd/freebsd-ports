--- ./src/Player.cpp.orig	Sun Mar 21 18:16:45 2004
+++ ./src/Player.cpp	Wed Apr 21 23:11:01 2004
@@ -252,7 +252,7 @@
 	// (we could uses two differents check sums, but the framework would be heavier)
 	//cs^=netPort;
 
-	int l=strnlen(name, 32);
+	int l=strlen(name);
 	for (int i=0; i<l; i++)
 		cs^=name[i];
 	
