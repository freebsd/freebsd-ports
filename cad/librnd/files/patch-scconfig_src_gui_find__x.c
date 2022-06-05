--- scconfig/src/gui/find_x.c.orig	2018-12-09 09:02:02 UTC
+++ scconfig/src/gui/find_x.c
@@ -41,9 +41,9 @@ int find_xopendisplay(const char *name, int logdepth, 
 		NL;
 
 	const char *node = "libs/gui/xopendisplay";
-	char **cflags,  *cflags_arr[]  = {"", "-I/opt/X11/include", "-I/usr/X11R6/include", NULL};
-	char **ldflags, *ldflags_arr[] = {"-lX11", "-L/opt/X11/lib -lX11", "-L/usr/X11R6/lib -lX11", NULL};
-	char **Lflags, *Lflags_arr[] =   {"",      "-L/opt/X11/lib",       "-L/usr/X11R6/lib", NULL};
+	char **cflags,  *cflags_arr[]  = {"-I%%LOCALBASE%%/include", "-I/opt/X11/include", "-I/usr/X11R6/include", NULL};
+	char **ldflags, *ldflags_arr[] = {"-L%%LOCALBASE%%/lib -lX11", "-L/opt/X11/lib -lX11", "-L/usr/X11R6/lib -lX11", NULL};
+	char **Lflags, *Lflags_arr[] =   {"-L%%LOCALBASE%%/lib",      "-L/opt/X11/lib",       "-L/usr/X11R6/lib", NULL};
 
 	if (require("cc/cc", logdepth, fatal))
 		return 1;
