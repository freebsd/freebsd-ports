--- dynload.cpp.orig	Thu Aug  9 03:39:30 2001
+++ dynload.cpp	Fri Oct  5 03:02:16 2001
@@ -24,7 +24,7 @@
 
 // we need __linux instead of just linux since the latter is not defined when -ansi is used.
 
-#if defined(__sparc) || defined(__linux) || defined(_WIN32) || defined(__OS2__)
+#if defined(__sparc) || defined(__linux) || defined(__FreeBSD__) || defined(_WIN32) || defined(__OS2__)
 #define HAVESHAREDLIBS
 #endif
 
@@ -48,6 +48,8 @@
 #include <dlfcn.h>
 typedef void (*initfunctype) ();
 //  static const char * const libsuffix = ".so";
+#elif defined(__FreeBSD__)
+#include <dlfcn.h>
 #elif defined(__sparc)
 #if defined(__SVR4)
 #include <dlfcn.h>
@@ -101,6 +103,9 @@
 #if defined(__linux)
 	int loadmode = RTLD_LAZY;	// RTLD_NOW
 	handle = dlopen(fulllibname, loadmode);
+#elif defined(__FreeBSD__)
+	int loadmode = RTLD_LAZY;	// RTLD_NOW
+	handle = dlopen(fulllibname, loadmode);
 #elif defined(__sparc)
 	int loadmode = RTLD_LAZY;	// RTLD_NOW
 	handle = dlopen(fulllibname, loadmode);
@@ -136,6 +141,8 @@
 	if (handle) {
 #if defined(__linux)
 		dlclose(handle);
+#elif defined(__FreeBSD__)
+		dlclose(handle);
 #elif defined(__sparc)
 		dlclose(handle);
 #elif defined(__OS2__)
@@ -163,6 +170,8 @@
 {
 #if defined(__linux)
 	DynLoader::fptr rfptr = (DynLoader::fptr) dlsym(handle, name);	//lint !e611 //: Suspicious cast
+#elif defined(__FreeBSD__)
+	DynLoader::fptr rfptr = (DynLoader::fptr) dlsym(handle, name);	//lint !e611 //: Suspicious cast
 #elif defined(__sparc)
 	DynLoader::fptr rfptr = (DynLoader::fptr) dlsym(handle, name);	//lint !e611 //: Suspicious cast
 #elif defined(__OS2__)
@@ -245,7 +254,7 @@
 //          globalRp->explainformats(errstream);
 }
 
-#if defined(__linux) || defined(__sparc) || defined(__OS2__)
+#if defined(__linux) || defined(__sparc) || defined(__FreeBSD__) || defined(__OS2__)
 // for directory search
 #include <dirent.h>
 
