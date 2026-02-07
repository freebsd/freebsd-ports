--- doomtype.h.orig	2000-01-07 20:42:41 UTC
+++ doomtype.h
@@ -59,9 +59,7 @@ typedef unsigned char byte;
 #define MININT		((int)0x80000000)
 #define MINLONG		((long)0x8000000000000000)
 
-#endif /* 64bit */
-
-#if defined(__32BIT__)
+#elif defined(__32BIT__)
 
 /* 32bit defines */
 
