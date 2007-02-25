--- engine/unix/unix_main.c.orig	Sat Dec 23 14:57:28 2006
+++ engine/unix/unix_main.c	Sat Dec 23 15:47:40 2006
@@ -673,12 +673,12 @@
 {
 	void           *libHandle;
 	void            (*dllEntry) (intptr_t (*syscallptr) (intptr_t, ...));
-	char            curpath[MAX_OSPATH];
 	char            fname[MAX_OSPATH];
 	char           *basepath;
 	char           *homepath;
 	char           *pwdpath;
 	char           *gamedir;
+	char           *libdir = "%%LIBDIR%%";
 	char           *fn;
 	const char     *err = NULL;
 
@@ -687,20 +687,7 @@
 	// bk001206 - let's have some paranoia
 	assert(name);
 
-	getcwd(curpath, sizeof(curpath));
-#if defined __i386__
-	snprintf(fname, sizeof(fname), "%si386.so", name);
-#elif defined __x86_64__
-	snprintf(fname, sizeof(fname), "%sx86_64.so", name);
-#elif defined __powerpc__		//rcg010207 - PPC support.
-	snprintf(fname, sizeof(fname), "%sppc.so", name);
-#elif defined __axp__
-	snprintf(fname, sizeof(fname), "%saxp.so", name);
-#elif defined __mips__
-	snprintf(fname, sizeof(fname), "%smips.so", name);
-#else
-#error Unknown arch
-#endif
+	snprintf(fname, sizeof(fname), "%s.so", name);
 
 // bk001129 - was RTLD_LAZY 
 #define Q_RTLD    RTLD_NOW
@@ -722,29 +709,34 @@
 		fn = FS_BuildOSPath(homepath, gamedir, fname);
 		Com_Printf("Sys_LoadDll(%s)... \n", fn);
 		libHandle = dlopen(fn, Q_RTLD);
+	}
 
-		if(!libHandle)
-		{
-			Com_Printf("Sys_LoadDll(%s) failed:\n\"%s\"\n", fn, dlerror());
-			// fs_basepath
-			fn = FS_BuildOSPath(basepath, gamedir, fname);
-			Com_Printf("Sys_LoadDll(%s)... \n", fn);
-			libHandle = dlopen(fn, Q_RTLD);
+	if(!libHandle)
+	{
+		Com_Printf("Sys_LoadDll(%s) failed:\n\"%s\"\n", fn, dlerror());
+		// libdir
+		fn = FS_BuildOSPath(libdir, gamedir, fname);
+		Com_Printf("Sys_LoadDll(%s)... \n", fn);
+		libHandle = dlopen(fn, Q_RTLD);
+	}
 
-			if(!libHandle)
-			{
-#ifndef NDEBUG					// bk001206 - in debug abort on failure
-				Com_Error(ERR_FATAL, "Sys_LoadDll(%s) failed dlopen() completely!\n", name);
+	if(!libHandle)
+	{
+		Com_Printf("Sys_LoadDll(%s) failed:\n\"%s\"\n", fn, dlerror());
+		// fs_basepath
+		fn = FS_BuildOSPath(basepath, gamedir, fname);
+		Com_Printf("Sys_LoadDll(%s)... \n", fn);
+		libHandle = dlopen(fn, Q_RTLD);
+	}
+
+	if(!libHandle)
+	{
+#ifndef NDEBUG			// bk001206 - in debug abort on failure
+		Com_Error(ERR_FATAL, "Sys_LoadDll(%s) failed dlopen() completely!\n", name);
 #else
-				Com_Printf("Sys_LoadDll(%s) failed dlopen() completely!\n", name);
+		Com_Printf("Sys_LoadDll(%s) failed dlopen() completely!\n", name);
 #endif
-				return NULL;
-			}
-			else
-				Com_Printf("Sys_LoadDll(%s): succeeded ...\n", fn);
-		}
-		else
-			Com_Printf("Sys_LoadDll(%s): succeeded ...\n", fn);
+		return NULL;
 	}
 	else
 		Com_Printf("Sys_LoadDll(%s): succeeded ...\n", fn);
