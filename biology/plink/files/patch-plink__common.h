--- plink_common.h.orig	2020-01-22 01:51:56 UTC
+++ plink_common.h
@@ -122,7 +122,7 @@
   #define EOLN_STR "\n"
   #define FOPEN_RB "r"
   #define FOPEN_WB "w"
-  #ifndef __APPLE__
+  #if !defined(__APPLE__) && !defined(__FreeBSD__)
     // argh
     // not sure what the right threshold actually is, but this works for now
     // (may break on gcc <3.0?  but that shouldn't matter anymore)
@@ -143,7 +143,7 @@
   #define CLZLU __builtin_clzl
   #ifndef __LP64__
     // attempt to patch GCC 6 build failure
-    #if (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
+    #if !defined(__FreeBSD__) && (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
       #ifndef uintptr_t
         #define uintptr_t unsigned long
       #endif
