--- src/views.cc.orig	Sat Dec 16 01:22:27 2000
+++ src/views.cc	Thu Apr  7 19:07:54 2005
@@ -45,12 +45,12 @@
 	int pos = file.rfind('.');
 	
 	if(pos != file.npos){
-		if(!file.compare(".h",pos,2)||
-		   !file.compare(".c",pos,2)||
-		   !file.compare(".C",pos,2)||
-		   !file.compare(".cc",pos,3)||
-		   !file.compare(".cpp",pos,4)||
-		   !file.compare(".cxx",pos,4))
+		if(!file.compare(pos,2,".h")||
+		   !file.compare(pos,2,".c")||
+		   !file.compare(pos,2,".C")||
+		   !file.compare(pos,3,".cc")||
+		   !file.compare(pos,4,".cpp")||
+		   !file.compare(pos,4,".cxx"))
 		res = "cpp";
 	};
 
