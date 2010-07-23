--- ./setup.c.orig	2010-07-22 11:30:51.186311264 -0400
+++ ./setup.c	2010-07-22 11:32:10.173155632 -0400
@@ -170,6 +170,8 @@
 	char path[PATH_MAX];
 	size_t len = strlen(suspect);
 
+	if (PATH_MAX <= len + strlen("/objects"))
+		die("Too long path: %.*s", 60, suspect);
 	strcpy(path, suspect);
 	if (getenv(DB_ENVIRONMENT)) {
 		if (access(getenv(DB_ENVIRONMENT), X_OK))
