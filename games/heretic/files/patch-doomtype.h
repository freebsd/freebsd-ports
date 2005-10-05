--- doomtype.h.orig	Wed Oct  5 07:40:18 2005
+++ doomtype.h	Wed Oct  5 07:40:41 2005
@@ -59,9 +59,7 @@
 #define MININT		((int)0x80000000)
 #define MINLONG		((long)0x8000000000000000)
 
-#endif /* 64bit */
-
-#if defined(__32BIT__)
+#elif defined(__32BIT__)
 
 /* 32bit defines */
 
