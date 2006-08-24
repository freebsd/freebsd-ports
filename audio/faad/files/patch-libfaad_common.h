--- libfaad/common.h.orig	Thu Aug 24 16:50:30 2006
+++ libfaad/common.h	Thu Aug 24 16:51:20 2006
@@ -310,6 +310,7 @@
 
 
   #if defined(_WIN32) && !defined(__MINGW32__)
+   #ifndef HAVE_LRINTF
     #define HAS_LRINTF
     static INLINE int lrintf(float f)
     {
@@ -335,6 +336,7 @@
             : "m" (f));
         return i;
     }
+    #endif /* HAVE_LRINTF */
   #endif
 
 
