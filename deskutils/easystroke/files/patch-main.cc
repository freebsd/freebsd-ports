--- main.cc~	2012-10-06 08:07:11.000000000 +0200
+++ main.cc	2013-02-12 17:29:51.103190380 +0100
@@ -1350,7 +1350,7 @@
 		config_dir += "/.easystroke";
 	}
 	struct stat st;
-	char *name = canonicalize_file_name(config_dir.c_str());
+	char *name = realpath(config_dir.c_str(), NULL);
 
 	// check if the directory does not exist
 	if (lstat(name, &st) == -1) {
