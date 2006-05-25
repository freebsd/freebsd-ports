--- code/unix/unix_main.c.orig	Thu May 25 16:59:37 2006
+++ code/unix/unix_main.c	Thu May 25 17:00:58 2006
@@ -707,12 +707,12 @@
 {
   void *libHandle;
   void  (*dllEntry)( int (*syscallptr)(int, ...) );
-  char  curpath[MAX_OSPATH];
   char  fname[MAX_OSPATH];
   char  *basepath;
   char  *homepath;
   char  *pwdpath;
   char  *gamedir;
+  char  *libdir = LIBDIR;
   char  *fn;
   const char*  err = NULL;
 	
@@ -721,18 +721,7 @@
   // bk001206 - let's have some paranoia
   assert( name );
 
-  getcwd(curpath, sizeof(curpath));
-#if defined __i386__
-  snprintf (fname, sizeof(fname), "%si386.so", name);
-#elif defined __powerpc__   //rcg010207 - PPC support.
-  snprintf (fname, sizeof(fname), "%sppc.so", name);
-#elif defined __axp__
-  snprintf (fname, sizeof(fname), "%saxp.so", name);
-#elif defined __mips__
-  snprintf (fname, sizeof(fname), "%smips.so", name);
-#else
-#error Unknown arch
-#endif
+  snprintf (fname, sizeof(fname), "%s.so", name);
 
 // bk001129 - was RTLD_LAZY 
 #define Q_RTLD    RTLD_NOW
@@ -742,10 +731,19 @@
   homepath = Cvar_VariableString( "fs_homepath" );
   gamedir = Cvar_VariableString( "fs_game" );
 
-  // pwdpath
-  fn = FS_BuildOSPath( pwdpath, gamedir, fname );
+  // libdir
+  fn = FS_BuildOSPath( libdir, gamedir, fname );
   Com_Printf( "Sys_LoadDll(%s)... \n", fn );
   libHandle = dlopen( fn, Q_RTLD );
+
+  // pwdpath
+  if ( !libHandle )
+  {
+    Com_Printf( "Sys_LoadDll(%s) failed:\n\"%s\"\n", fn, dlerror() );
+    fn = FS_BuildOSPath( pwdpath, gamedir, fname );
+    Com_Printf( "Sys_LoadDll(%s)... \n", fn );
+    libHandle = dlopen( fn, Q_RTLD );
+  }
 
   if ( !libHandle )
   {
