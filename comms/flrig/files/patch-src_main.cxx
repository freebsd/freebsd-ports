--- src/main.cxx.orig	2018-01-18 20:38:50 UTC
+++ src/main.cxx
@@ -514,7 +514,7 @@ int parse_args(int argc, char **argv, int& idx)
 		exit(0);
 	} 
 	if (strcasecmp("--version", argv[idx]) == 0) {
-		printf("Version: "VERSION"\n");
+		printf("Version: %s\n",VERSION);
 		exit (0);
 	}
 	if (strcasecmp("--rig_debug", argv[idx]) == 0) {
