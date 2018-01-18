--- src/flwrap.cxx.orig	2018-01-18 20:57:00 UTC
+++ src/flwrap.cxx
@@ -547,7 +547,7 @@ int parse_args(int argc, char **argv, int& idx)
 			exit(0);
 		}
 	if (strcasecmp("--version", argv[idx]) == 0) {
-		printf("Version: "VERSION"\n");
+		printf("Version: %s\n",VERSION);
 		exit(0);
 	}
 
