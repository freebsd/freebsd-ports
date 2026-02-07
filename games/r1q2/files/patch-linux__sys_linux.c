--- ./linux/sys_linux.c.orig	Mon Oct 30 15:26:12 2006
+++ ./linux/sys_linux.c	Sat Dec 16 17:28:37 2006
@@ -177,7 +177,7 @@
 /* Obtain a backtrace and print it to stderr. 
  * Adapted from http://www.delorie.com/gnu/docs/glibc/libc_665.html
  */
-#ifdef __x86_64__
+#ifndef __i386__
 void Sys_Backtrace (int sig)
 #else
 void Sys_Backtrace (int sig, siginfo_t *siginfo, void *secret)
@@ -188,7 +188,7 @@
 	size_t		size;
 	size_t		i;
 	char		**strings;
-#ifndef __x86_64__
+#ifdef __i386__
 	ucontext_t 	*uc = (ucontext_t *)secret;
 #endif
 
@@ -214,9 +214,13 @@
 
 	size = backtrace (array, sizeof(array)/sizeof(void*));
 
-#ifndef __x86_64__
+#ifdef __i386__
+#ifdef __FreeBSD__
+	array[1] = (void *) uc->uc_mcontext.mc_eip;
+#else	/* __linux__ */
 	array[1] = (void *) uc->uc_mcontext.gregs[REG_EIP];
 #endif
+#endif
 	
 	strings = backtrace_symbols (array, size);
 
@@ -246,7 +250,7 @@
 //	Sys_SetFPCW();
 #endif
   /* Install our signal handler */
-#ifndef __x86_64__
+#ifdef __i386__
 	struct sigaction sa;
 
 	if (sizeof(uint32) != 4)
@@ -393,29 +397,17 @@
 	void	*(*GetGameAPI) (void *);
 
 	char	name[MAX_OSPATH];
-	char	curpath[MAX_OSPATH];
 	char	*path;
-#ifdef __i386__
-	const char *gamename = "gamei386.so";
-#elif defined __alpha__
-	const char *gamename = "gameaxp.so";
-#elif defined __x86_64__
-	const char *gamename = "gamex86_64.so";
-#else
-#error "Don't know what kind of dynamic objects to use for this architecture."
-#endif
+	const char *gamename = "game.so";
 
 	if (game_library)
 		Com_Error (ERR_FATAL, "Sys_GetGameAPI without Sys_UnloadingGame");
 
-	getcwd(curpath, sizeof(curpath)-1);
-	curpath[sizeof(curpath)-1] = 0;
-
 	Com_Printf("------- Loading %s -------\n", LOG_SERVER|LOG_NOTICE, gamename);
 
 	if (baseq2)
 	{
-		Com_sprintf (name, sizeof(name), "%s/%s/%s", curpath, BASEDIRNAME, gamename);
+		Com_sprintf (name, sizeof(name), "%s/%s", BASEDIRNAME, gamename);
 		game_library = dlopen (name, RTLD_NOW );
 
 		if (game_library == NULL) {
@@ -433,7 +425,7 @@
 			path = FS_NextPath (path);
 			if (!path)
 				return NULL;		// couldn't find one anywhere
-			Com_sprintf (name, sizeof(name), "%s/%s/%s", curpath, path, gamename);
+			Com_sprintf (name, sizeof(name), "%s/%s", path, gamename);
 			game_library = dlopen (name, RTLD_NOW );
 			if (game_library)
 			{
