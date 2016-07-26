--- faad2/libfaad/common.h.orig	2004-09-08 09:43:12 UTC
+++ faad2/libfaad/common.h
@@ -302,6 +302,7 @@ char *strchr(), *strrchr();
         return i;
     }
   #elif (defined(__i386__) && defined(__GNUC__))
+#if 0
     #define HAS_LRINTF
     // from http://www.stereopsis.com/FPU.html
     static INLINE int lrintf(float f)
@@ -315,7 +316,7 @@ char *strchr(), *strrchr();
         return i;
     }
   #endif
-
+#endif
 
   #ifdef __ICL /* only Intel C compiler has fmath ??? */
 
