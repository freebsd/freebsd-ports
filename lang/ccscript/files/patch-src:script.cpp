--- src/script.cpp.orig	Fri Feb 20 17:51:13 2004
+++ src/script.cpp	Fri Feb 20 17:52:01 2004
@@ -1209,7 +1209,7 @@
 #endif
 	for(;;)
 	{
-		scrname = dir.getName();
+		scrname = (char*)dir.getName();
 		if(!scrname)
 			break;
 		ext = strchr(scrname, '.');
