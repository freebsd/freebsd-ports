--- engine/unix/unix_main.c.orig	Fri Apr 20 23:34:22 2007
+++ engine/unix/unix_main.c	Fri Apr 20 23:43:23 2007
@@ -765,6 +765,7 @@
   void  (*dllEntry)( intptr_t (*syscallptr)(intptr_t, ...) );
   char  curpath[MAX_OSPATH];
   char  fname[MAX_OSPATH];
+  char  *libpath;
   char  *basepath;
   char  *homepath;
   char  *pwdpath;
@@ -776,10 +777,11 @@
   assert( name );
 
   getcwd(curpath, sizeof(curpath));
-  snprintf (fname, sizeof(fname), "%s" ARCH_STRING DLL_EXT, name);
+  snprintf (fname, sizeof(fname), "%s" DLL_EXT, name);
 
   // TODO: use fs_searchpaths from files.c
   pwdpath = Sys_Cwd();
+  libpath = LIBDIR;
   basepath = Cvar_VariableString( "fs_basepath" );
   homepath = Cvar_VariableString( "fs_homepath" );
   cdpath = Cvar_VariableString( "fs_cdpath" );
@@ -789,6 +791,9 @@
 
   if(!libHandle && homepath)
     libHandle = try_dlopen(homepath, gamedir, fname, fqpath);
+
+  if(!libHandle && libpath)
+    libHandle = try_dlopen(libpath, gamedir, fname, fqpath);
 
   if(!libHandle && basepath)
     libHandle = try_dlopen(basepath, gamedir, fname, fqpath);
