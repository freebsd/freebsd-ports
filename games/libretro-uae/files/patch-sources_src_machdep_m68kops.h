--- sources/src/machdep/m68kops.h.orig	2020-08-25 11:26:10 UTC
+++ sources/src/machdep/m68kops.h
@@ -11,7 +11,7 @@
 
 #ifndef ANDROID
 
-#if defined(__CELLOS_LV2__) || defined(_WIN32) || defined(__x86_64__) || defined(ARM) || defined(WIIU)
+#if defined(__CELLOS_LV2__) || defined(_WIN32) || defined(__x86_64__) || defined(ARM) || defined(WIIU) || defined(__powerpc__)
 
 #ifdef WIIU
 #define FLAGBIT_N	31
