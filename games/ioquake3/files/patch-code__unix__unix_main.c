--- ./code/unix/unix_main.c.orig	Sun Feb 26 18:22:12 2006
+++ ./code/unix/unix_main.c	Sun Jun 11 17:26:26 2006
@@ -774,6 +774,7 @@
   char  curpath[MAX_OSPATH];
   char  fname[MAX_OSPATH];
   char  *basepath;
+  char  *libpath;
   char  *homepath;
   char  *pwdpath;
   char  *cdpath;
@@ -789,14 +790,19 @@
   // TODO: use fs_searchpaths from files.c
   pwdpath = Sys_Cwd();
   basepath = Cvar_VariableString( "fs_basepath" );
+  libpath = LIBDIR;
   homepath = Cvar_VariableString( "fs_homepath" );
   cdpath = Cvar_VariableString( "fs_cdpath" );
   gamedir = Cvar_VariableString( "fs_game" );
 
-  libHandle = try_dlopen(pwdpath, gamedir, fname, fqpath);
+  if(!libHandle && homepath)
+    libHandle = try_dlopen(pwdpath, gamedir, fname, fqpath);
 
   if(!libHandle && homepath)
     libHandle = try_dlopen(homepath, gamedir, fname, fqpath);
+
+  if(!libHandle && basepath)
+    libHandle = try_dlopen(libpath, gamedir, fname, fqpath);
 
   if(!libHandle && basepath)
     libHandle = try_dlopen(basepath, gamedir, fname, fqpath);
