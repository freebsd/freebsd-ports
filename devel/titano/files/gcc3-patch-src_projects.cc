--- src/projects.cc.orig	Sat Dec  9 23:13:32 2000
+++ src/projects.cc	Thu Apr  7 19:10:08 2005
@@ -100,13 +100,13 @@
 	int pos = name.rfind('.');
 	
 	if(pos != name.npos){
-		if(!name.compare(".h",pos,2))
+		if(!name.compare(pos,2,".h"))
 			res = C_HEADER;
-		if(!name.compare(".c",pos,2)||
-		   !name.compare(".C",pos,2)||
-		   !name.compare(".cc",pos,3)||
-		   !name.compare(".cpp",pos,4)||
-		   !name.compare(".cxx",pos,4))
+		if(!name.compare(pos,2,".c")||
+		   !name.compare(pos,2,".C")||
+		   !name.compare(pos,3,".cc")||
+		   !name.compare(pos,4,".cpp")||
+		   !name.compare(pos,4,".cxx"))
 			res = C_SOURCE;
 	};
 
