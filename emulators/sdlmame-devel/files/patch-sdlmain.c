--- src/osd/sdl/sdlmain.c.orig	2009-03-25 05:55:00.000000000 +0100
+++ src/osd/sdl/sdlmain.c	2009-03-25 05:56:04.000000000 +0100
@@ -82,7 +82,7 @@
 #ifdef MESS
 	{ "inipath",                              "$HOME/.mess;.;ini",     0,     "path to ini files" },
 #else
-	{ SDLOPTION_INIPATH,                     "$HOME/.mame;.;ini",     0,     "path to ini files" },
+	{ SDLOPTION_INIPATH,                     "$HOME/.mame-devel;.;ini",     0,     "path to ini files" },
 #endif // MESS
 #endif // INI_PATH
 #endif // MACOSX
