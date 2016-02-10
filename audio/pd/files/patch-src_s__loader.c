--- src/s_loader.c.orig	2014-08-18 00:35:53 UTC
+++ src/s_loader.c
@@ -2,7 +2,7 @@
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */
 
-#ifdef HAVE_LIBDL
+#if defined(HAVE_LIBDL) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 #ifdef HAVE_UNISTD_H
@@ -37,11 +37,9 @@ objects.  The specific name is the lette
 darwin, or microsoft, followed by a more specific string, either "fat" for
 a fat binary or an indication of the instruction set. */
 
-#ifdef __FreeBSD__
-static char sys_dllextent[] = ".b_i386", sys_dllextent2[] = ".pd_freebsd";
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__GNU__) || defined(__FreeBSD__)
 static char sys_dllextent2[] = ".pd_linux";
-# ifdef __x86_64__
+# ifdef __amd64__
 static char sys_dllextent[] = ".l_ia64"; // this should be .l_x86_64 or .l_amd64
 # elif defined(__i386__) || defined(_M_IX86)
 static char sys_dllextent[] = ".l_i386";
@@ -216,7 +214,7 @@ gotone:
              makeout = (t_xxx)GetProcAddress(ntdll, "setup");
         SetDllDirectory(NULL); /* reset DLL dir to nothing */
     }
-#elif defined HAVE_LIBDL
+#elif defined(HAVE_LIBDL) || defined(__FreeBSD__)
     dlobj = dlopen(filename, RTLD_NOW | RTLD_GLOBAL);
     if (!dlobj)
     {
