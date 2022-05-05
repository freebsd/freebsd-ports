--- src/main.cxx.orig	2022-03-18 02:06:06 UTC
+++ src/main.cxx
@@ -1174,7 +1174,7 @@ int main (int argc, char *argv[])
 	setTabColors();
 
 	progdefaults.testCommPorts();
-	init_hids();
+	//init_hids();
 
 #if USE_HAMLIB
 	xcvr = new Rig();
