--- faad2/libfaad/common.h.orig	Sun May 28 19:33:36 2006
+++ faad2/libfaad/common.h	Sun May 28 19:35:11 2006
@@ -302,6 +302,7 @@
         return i;
     }
   #elif (defined(__i386__) && defined(__GNUC__))
+#if 0
     #define HAS_LRINTF
     // from http://www.stereopsis.com/FPU.html
     static INLINE int lrintf(float f)
@@ -315,7 +316,7 @@
         return i;
     }
   #endif
-
+#endif
 
   #ifdef __ICL /* only Intel C compiler has fmath ??? */
 
