--- unix/unix_main.c.orig	Mon Jul 24 14:03:13 2006
+++ unix/unix_main.c	Mon Jul 24 14:06:39 2006
@@ -44,10 +44,6 @@
 #include "../common/common.h"
 #include "unix_local.h"
 
-#if defined(__FreeBSD__)
-#include <machine/param.h>
-#endif
-
 uid_t	saved_euid;
 
 #ifndef DEDICATED_ONLY
@@ -623,8 +619,8 @@
 } libList_t;
 
 static libList_t sys_libList[LIB_MAX] = {
-	{ "LIB_CGAME",	NULL,	"eglcgame" LIBARCH ".so",	"GetCGameAPI"	},
-	{ "LIB_GAME",	NULL,	"game" LIBARCH ".so",		"GetGameAPI"	},
+	{ "LIB_CGAME",	NULL,	"eglcgame.so",	"GetCGameAPI"	},
+	{ "LIB_GAME",	NULL,	"game.so",		"GetGameAPI"	},
 };
 
 /*
@@ -660,7 +656,6 @@
 void *Sys_LoadLibrary (libType_t libType, void *parms)
 {
 	char		name[MAX_OSPATH];
-	char		cwd[MAX_OSPATH];
 	char		*path;
 	void		*(*APIfunc) (void *);
 	void		**lib;
@@ -713,8 +708,7 @@
 		Com_Error (ERR_FATAL, "Sys_LoadLibrary (%s) without Sys_UnloadLibrary", sys_libList[libType].title);
 
 	// Check the current debug directory first for development purposes
-	getcwd (cwd, sizeof(cwd));
-	Q_snprintfz (name, sizeof(name), "%s/%s/%s", cwd, debugdir, libName);
+	Q_snprintfz (name, sizeof(name), "%s/%s", debugdir, libName);
 	*lib = dlopen (name,  RTLD_NOW);
 
 	if (*lib) {
