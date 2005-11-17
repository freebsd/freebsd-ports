--- src/linux/vid_so.c.orig	Fri Sep 24 19:11:44 2004
+++ src/linux/vid_so.c	Tue Sep 27 19:28:29 2005
@@ -216,7 +216,6 @@
 	refimport_t	ri;
 	GetRefAPI_t	GetRefAPI;
 	char	fn[MAX_OSPATH];
-	char	*path;
 	struct stat st;
 	extern uid_t saved_euid;
 	
@@ -237,9 +236,7 @@
 	//regain root
 	seteuid(saved_euid);
 
-	path = Cvar_Get ("basedir", ".", CVAR_NOSET)->string;
-
-	snprintf (fn, MAX_OSPATH, "%s/%s", path, name );
+	snprintf (fn, MAX_OSPATH, LIBDIR"/%s", name );
 	
 	if (stat(fn, &st) == -1) {
 		Com_Printf( "LoadLibrary(\"%s\") failed: %s\n", name, strerror(errno));
@@ -490,11 +487,9 @@
 qboolean VID_CheckRefExists (const char *ref)
 {
 	char	fn[MAX_OSPATH];
-	char	*path;
 	struct stat st;
 
-	path = Cvar_Get ("basedir", ".", CVAR_NOSET)->string;
-	snprintf (fn, MAX_OSPATH, "%s/ref_%s.so", path, ref );
+	snprintf (fn, MAX_OSPATH, LIBDIR"/ref_%s.so", ref );
 	
 	if (stat(fn, &st) == 0)
 		return true;
