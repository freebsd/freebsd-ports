--- src/titano-app.cc.orig	Fri Dec 29 19:52:11 2000
+++ src/titano-app.cc	Thu Apr  7 18:28:24 2005
@@ -410,7 +410,7 @@
 
 void TitanoApp::open_project(const string &filename)
 {
-	if(filename.rfind('.') == filename.npos || filename.compare(".titano",filename.rfind('.'),7)){
+	if(filename.rfind('.') == filename.npos || filename.compare(filename.rfind('.'),7,".titano")){
 		throw Exception("File " + filename + " is not a Titano project.");	       
 	};
 	
