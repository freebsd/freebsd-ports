--- src/util.cpp.orig	Tue Oct  1 20:41:14 2002
+++ src/util.cpp	Tue May 13 16:10:35 2003
@@ -160,6 +160,7 @@
 	if (cfg.query("dirs", "data"))
 	{
 		filepath = cfg.query("dirs", "data");
+		filepath += "/";
 		filepath += pos_dir;
 		filepath += file;
 
@@ -171,6 +172,7 @@
 	}
 
 	filepath = DATADIR;
+	filepath += "/";
 	filepath += pos_dir;
 	filepath += file;
 
