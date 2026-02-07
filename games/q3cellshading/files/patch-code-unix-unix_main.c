--- code/unix/unix_main.c.orig	2006-07-18 09:52:58 UTC
+++ code/unix/unix_main.c
@@ -55,9 +55,6 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 
 #include "linux_local.h" // bk001204
 
-// Structure containing functions exported from refresh DLL
-refexport_t re;
-
 unsigned  sys_frame_time;
 
 uid_t saved_euid;
@@ -707,12 +704,12 @@ void *Sys_LoadDll( const char *name, char *fqpath ,
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
 	
@@ -721,18 +718,7 @@ void *Sys_LoadDll( const char *name, char *fqpath ,
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
@@ -742,10 +728,19 @@ void *Sys_LoadDll( const char *name, char *fqpath ,
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
