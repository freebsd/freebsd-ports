--- src/main.cxx.orig	2023-08-24 15:22:40 UTC
+++ src/main.cxx
@@ -1182,7 +1182,7 @@ int main (int argc, char *argv[])
 	setTabColors();
 
 	progdefaults.testCommPorts();
-	init_hids();
+	//init_hids();
 
 #if USE_HAMLIB
 	xcvr = new Rig();
