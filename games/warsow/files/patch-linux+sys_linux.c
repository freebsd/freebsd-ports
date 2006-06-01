--- linux/sys_linux.c.orig	Thu May 11 22:18:54 2006
+++ linux/sys_linux.c	Thu Jun  1 15:44:44 2006
@@ -377,53 +377,11 @@
 	char *libname;
 	char *apifuncname;
 
-#if defined __i386__
-#define ARCH "i386"
-
-#ifdef NDEBUG
-	const char *debugdir = "releasei386";
-#else
-	const char *debugdir = "debugi386";
-#endif
-
-#elif defined __x86_64__
-#define ARCH "x86_64"
-#ifdef NDEBUG
-	const char *debugdir = "releasex86_64";
-#else
-	const char *debugdir = "debugx86_64";
-#endif
-
-#elif defined __alpha__
-#define ARCH "axp"
-#ifdef NDEBUG
-	const char *debugdir = "releaseaxp";
-#else
-	const char *debugdir = "debugaxp";
-#endif
-
-#elif defined __powerpc__
-#define ARCH "ppc"
-#ifdef NDEBUG
-	const char *debugdir = "releaseppc";
-#else
-	const char *debugdir = "debugppc";
-#endif
-#elif defined __sparc__
-#define ARCH "sparc"
-#ifdef NDEBUG
-	const char *debugdir = "releasepsparc";
-#else
-	const char *debugdir = "debugpsparc";
-#endif
-#else
-#define ARCH	"UNKNOW"
 #ifdef NDEBUG
 	const char *debugdir = "release";
 #else
 	const char *debugdir = "debug";
 #endif
-#endif
 
 	APIfunc = NULL;
 	switch( gamelib ) {
@@ -434,7 +392,7 @@
 			APIfunc = GetGameAPI;
 #endif
 			lib = &game_library;
-			libname = "game_" ARCH ".so";
+			libname = "game.so";
 			apifuncname = "GetGameAPI";
 			break;
 		}
@@ -445,7 +403,7 @@
 			APIfunc = GetCGameAPI;
 #endif
 			lib = &cgame_library;
-			libname = "cgame_" ARCH ".so";
+			libname = "cgame.so";
 			apifuncname = "GetCGameAPI";
 			break;
 		}
@@ -456,7 +414,7 @@
 			APIfunc = GetUIAPI;
 #endif
 			lib = &ui_library;
-			libname = "ui_" ARCH ".so";
+			libname = "ui.so";
 			apifuncname = "GetUIAPI";
 			break;
 		}
