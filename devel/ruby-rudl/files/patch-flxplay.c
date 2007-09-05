--- flxplay.c.orig	Wed Jul 25 11:40:05 2007
+++ flxplay.c	Wed Jul 25 11:40:27 2007
@@ -42,8 +42,8 @@
   int lastFrameTicks;
 } FLC;
 
-#define ReadU16(tmp1, tmp2) (Uint16)*(tmp1) = ((Uint8)*(tmp2+1)<<8)+(Uint8)*(tmp2);
-#define ReadU32(tmp1, tmp2) (Uint32)*(tmp1) = (((((((Uint8)*(tmp2+3)<<8)+((Uint8)*(tmp2+2)))<<8)+((Uint8)*(tmp2+1)))<<8)+(Uint8)*(tmp2));
+#define ReadU16(tmp1, tmp2) *(Uint16 *)(tmp1) = ((Uint8)*(tmp2+1)<<8)+(Uint8)*(tmp2);
+#define ReadU32(tmp1, tmp2) *(Uint32 *)(tmp1) = (((((((Uint8)*(tmp2+3)<<8)+((Uint8)*(tmp2+2)))<<8)+((Uint8)*(tmp2+1)))<<8)+(Uint8)*(tmp2));
 
 
 
