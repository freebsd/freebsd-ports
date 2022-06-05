--- scconfig/src/gui/find_lesstif2.c.orig	2022-05-06 17:10:54 UTC
+++ scconfig/src/gui/find_lesstif2.c
@@ -45,8 +45,8 @@ int find_lesstif2(const char *name, int logdepth, int 
 		NL;
 
 	const char *node = "libs/gui/lesstif2";
-	char **cflags,  *cflags_arr[]  = {"", "-I/opt/X11/include", NULL};
-	char **ldflags, *ldflags_arr[] = {"-lXm -lX11", "-lXm -lXt", "-L/opt/X11/lib -lXm -lXt  -lX11", NULL}; /* note: -lXt must be after -lXm else lesstif fails to init with runtime error */
+	char **cflags,  *cflags_arr[]  = {"-I%%LOCALBASE%%/include", "", "-I/opt/X11/include", NULL};
+	char **ldflags, *ldflags_arr[] = {"%%MOTIFLIB%% -lXt -lX11", "-lXm -lX11", "-lXm -lXt", "-L/opt/X11/lib -lXm -lXt  -lX11", NULL}; /* note: -lXt must be after -lXm else lesstif fails to init with runtime error */
 
 	if (require("cc/cc", logdepth, fatal))
 		return 1;
