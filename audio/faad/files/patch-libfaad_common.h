--- libfaad/common.h.orig	Fri Feb  6 13:55:24 2004
+++ libfaad/common.h	Wed Jan 19 01:52:32 2005
@@ -308,6 +308,7 @@
         return i;
     }
   #elif (defined(__i386__) && defined(__GNUC__))
+    #ifndef HAVE_LRINTF
     #define HAS_LRINTF
     // from http://www.stereopsis.com/FPU.html
     static INLINE int lrintf(float f)
@@ -320,6 +321,7 @@
             : "m" (f));
         return i;
     }
+    #endif /* HAVE_LRINTF */
   #endif
