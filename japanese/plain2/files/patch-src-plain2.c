--- src/plain2.c.orig	2013-11-24 13:27:57.000000000 +0900
+++ src/plain2.c	2013-11-24 13:45:59.000000000 +0900
@@ -643,7 +643,7 @@
 	char	buf[MAX_LINE_LEN];
 	FILE	*initf;
 	if ((plainEnv = getenv(PLAIN2_ENV)) == NULL)
-		return;
+		return 0;
 	if ((initf = fopen(plainEnv, "r")) == NULL) {
 		char	envOpt[MAX_LINE_LEN];
 		strcpy(envOpt, plainEnv);
@@ -669,6 +669,7 @@
 		}
 		fclose(initf);
 	}
+	return 0;
 }
 /*
  * Save & Restore Parameters for Parsing
