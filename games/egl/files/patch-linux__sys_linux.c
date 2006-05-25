--- ./linux/sys_linux.c.orig	Tue May 23 20:05:59 2006
+++ ./linux/sys_linux.c	Tue May 23 20:06:00 2006
@@ -43,10 +43,6 @@
 
 #include "../common/common.h"
 
-#if defined(__FreeBSD__)
-#include <machine/param.h>
-#endif
-
 uint32	sys_frameTime;
 int	sys_currTime;
 
@@ -607,7 +603,6 @@
 void *Sys_LoadLibrary (libType_t libType, void *parms)
 {
 	char name[MAX_OSPATH];
-	char cwd[MAX_OSPATH];
 	char *path;
 	void *(*APIfunc) (void *);
 	void **lib;
@@ -657,13 +652,13 @@
 	switch (libType) {
 	case LIB_CGAME:
 		lib = &cGameLib;
-		libname = "eglcgame" ARCH ".so";
+		libname = "eglcgame.so";
 		apifuncname = "GetCGameAPI";
 		break;
 
 	case LIB_GAME:
 		lib = &gameLib;
-		libname = "game" ARCH ".so";
+		libname = "game.so";
 		apifuncname = "GetGameAPI";
 		break;
 
@@ -673,8 +668,7 @@
 	}
 
 	// check the current debug directory first for development purposes
-	getcwd (cwd, sizeof(cwd));
-	Q_snprintfz (name, sizeof(name), "%s/%s/%s", cwd, debugdir, libname);
+	Q_snprintfz (name, sizeof(name), "%s/%s", debugdir, libname);
 	*lib = dlopen (name,  RTLD_NOW);
 
 	if (*lib) {
@@ -697,8 +691,10 @@
 				Com_DevPrintf (0, "dlopen (%s)\n", name);
 				break;
 			}
+#if 0
 			if (!*lib && (error = dlerror()))
 				Com_Printf (PRNT_ERROR, "dlopen (%s): %s\n", name, error);
+#endif
 		}
 	}
 
