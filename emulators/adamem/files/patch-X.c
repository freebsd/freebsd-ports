--- X.c.orig	Wed Sep 22 13:33:07 2004
+++ X.c	Wed Sep 22 13:33:49 2004
@@ -1370,41 +1370,41 @@
  return 2;
 }
 
-static void PutPixel32_0 (int offset,int c)
+FASTCALL static void PutPixel32_0 (int offset,int c)
 {
  *(unsigned*)(DisplayBuf+offset*4)=c;
 }
 
-static void PutPixel16_0 (int offset,int c)
+FASTCALL static void PutPixel16_0 (int offset,int c)
 {
  *(unsigned short*)(DisplayBuf+offset*2)=c;
 }
 
-static void PutPixel8_0 (int offset,int c)
+FASTCALL static void PutPixel8_0 (int offset,int c)
 {
  DisplayBuf[offset]=c;
 }
 
-static void PutPixel32_1 (int offset,int c)
+FASTCALL static void PutPixel32_1 (int offset,int c)
 {
  *(unsigned*)(DisplayBuf+offset*4*2)=
  *(unsigned*)(DisplayBuf+offset*4*2+1)=
  c;
 }
 
-static void PutPixel16_1 (int offset,int c)
+FASTCALL static void PutPixel16_1 (int offset,int c)
 {
  *(unsigned short*)(DisplayBuf+offset*2*2)=
  *(unsigned short*)(DisplayBuf+offset*2*2+1)=
  c;
 }
 
-static void PutPixel8_1 (int offset,int c)
+FASTCALL static void PutPixel8_1 (int offset,int c)
 {
  DisplayBuf[offset*2]=DisplayBuf[offset*2+1]=c;
 }
 
-static void PutPixel32_2 (int offset,int c)
+FASTCALL static void PutPixel32_2 (int offset,int c)
 {
  offset=(offset&0x00FF)+((offset&0xFF00)<<1);
  *(unsigned*)(DisplayBuf+offset*4*2)=
@@ -1412,7 +1412,7 @@
  c;
 }
 
-static void PutPixel16_2 (int offset,int c)
+FASTCALL static void PutPixel16_2 (int offset,int c)
 {
  offset=(offset&0x00FF)+((offset&0xFF00)<<1);
  *(unsigned short*)(DisplayBuf+offset*2*2)=
@@ -1420,7 +1420,7 @@
  c;
 }
 
-static void PutPixel8_2 (int offset,int c)
+FASTCALL static void PutPixel8_2 (int offset,int c)
 {
  offset=(offset&0x00FF)+((offset&0xFF00)<<1);
  DisplayBuf[offset*2]=DisplayBuf[offset*2+1]=c;
