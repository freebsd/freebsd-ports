--- scconfig/src/gui/find_misc.c.orig	2022-05-06 18:29:16 UTC
+++ scconfig/src/gui/find_misc.c
@@ -45,8 +45,8 @@ int find_libstroke(const char *name, int logdepth, int
 		NL;
 
 	const char *node = "libs/gui/libstroke";
-	char **cflags,  *cflags_arr[]  = {"", NULL};
-	char **ldflags, *ldflags_arr[] = {"-lstroke", NULL};
+	char **cflags,  *cflags_arr[]  = {"-I%%LOCALBASE%%/include", NULL};
+	char **ldflags, *ldflags_arr[] = {"-L%%LOCALBASE%%/lib -lstroke", NULL};
 
 	if (require("cc/cc", logdepth, fatal))
 		return 1;
