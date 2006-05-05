--- ./sys_linux.c.orig	Thu May 19 17:56:13 2005
+++ ./sys_linux.c	Sun Feb 26 11:23:56 2006
@@ -230,7 +230,7 @@
 
 	size = backtrace (array, sizeof(array)/sizeof(void*));
 
-#ifndef __x86_64__
+#if !defined(__x86_64__) && !defined(__FreeBSD__)
 	array[1] = (void *) uc->uc_mcontext.gregs[REG_EIP];
 #endif
 	
@@ -423,7 +423,7 @@
 
 	if (baseq2)
 	{
-		Com_sprintf (name, sizeof(name), "%s/%s/%s", curpath, BASEDIRNAME, gamename);
+		Com_sprintf (name, sizeof(name), "%s/%s/%s", LIBDIR, BASEDIRNAME, gamename);
 		game_library = dlopen (name, RTLD_NOW );
 	}
 	else
@@ -435,7 +435,7 @@
 			path = FS_NextPath (path);
 			if (!path)
 				return NULL;		// couldn't find one anywhere
-			Com_sprintf (name, sizeof(name), "%s/%s/%s", curpath, path, gamename);
+			Com_sprintf (name, sizeof(name), "%s/%s", path, gamename);
 			game_library = dlopen (name, RTLD_NOW );
 			if (game_library)
 			{
