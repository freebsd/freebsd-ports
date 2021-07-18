--- src/main.cxx.orig	2021-07-01 19:46:20 UTC
+++ src/main.cxx
@@ -1165,7 +1165,7 @@ int main(int argc, char ** argv)
 	setTabColors();
 
 	progdefaults.testCommPorts();
-	init_hids();
+	//init_hids();
 
 #if USE_HAMLIB
 	xcvr = new Rig();
