--- ./client/snd_openal.c.orig	Tue May 23 20:05:59 2006
+++ ./client/snd_openal.c	Tue May 23 20:06:00 2006
@@ -40,7 +40,7 @@
 # define AL_FREELIB(a)		FreeLibrary (a)
 #endif
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#ifdef __unix__
 # include <dlfcn.h>
 # include <unistd.h>
 # include <sys/types.h>
