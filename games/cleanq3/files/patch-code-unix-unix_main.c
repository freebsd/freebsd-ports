--- code/unix/unix_main.c.orig	Mon Mar 20 18:39:10 2006
+++ code/unix/unix_main.c	Mon Mar 20 20:24:22 2006
@@ -722,17 +722,7 @@
   assert( name );
 
   getcwd(curpath, sizeof(curpath));
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
@@ -765,12 +755,22 @@
 
       if ( !libHandle )
       {
+        Com_Printf( "Sys_LoadDll(%s) failed:\n\"%s\"\n", fn, dlerror() );
+        // FreeBSD package installation path
+        fn = FS_BuildOSPath( "%%PREFIX%%/lib/cleanq3", gamedir, fname );
+        Com_Printf( "Sys_LoadDll(%s)... \n", fn );
+        libHandle = dlopen( fn, Q_RTLD );
+
+      if ( !libHandle )
+      {
 #ifndef NDEBUG // bk001206 - in debug abort on failure
         Com_Error ( ERR_FATAL, "Sys_LoadDll(%s) failed dlopen() completely!\n", name  );
 #else
         Com_Printf ( "Sys_LoadDll(%s) failed dlopen() completely!\n", name );
 #endif
         return NULL;
+      } else
+        Com_Printf ( "Sys_LoadDll(%s): succeeded ...\n", fn );
       } else
         Com_Printf ( "Sys_LoadDll(%s): succeeded ...\n", fn );
     } else
