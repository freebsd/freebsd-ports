--- ./linux/vid_so.c.orig	Fri May 19 17:48:09 2006
+++ ./linux/vid_so.c	Fri May 19 17:49:23 2006
@@ -196,7 +196,6 @@
 
 	char	fn[MAX_OSPATH];
 	struct stat st;
-	char 	*path;
 	
 	if ( reflib_active )
 	{
@@ -212,17 +211,12 @@
 
 	Com_Printf( "------- Loading %s -------\n", LOG_CLIENT, name);
 	
-	path = Cvar_Get ("basedir", ".", CVAR_NOSET)->string;
-	snprintf (fn, MAX_OSPATH, "%s/%s", path, name );
+	snprintf (fn, MAX_OSPATH, "%s/%s", LIBDIR, name );
 
 	if (stat(fn, &st) == -1) {
 			Com_Printf( "LoadLibrary(\"%s\") failed: %s\n", LOG_CLIENT, name, strerror(errno));
 			return false;
 	}
-
-	strcpy (fn, ".");
-	strcat(fn, "/");
-	strcat(fn, name);
 
 	if ( ( reflib_library = dlopen( fn, RTLD_NOW ) ) == 0 )
 	{
