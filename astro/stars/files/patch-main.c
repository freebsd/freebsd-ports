--- main.c.orig	1996-04-10 10:58:49 UTC
+++ main.c
@@ -48,7 +48,7 @@ void setup();
 void events();
 void shutdn();
 
-void main()
+int main()
 {
   setup();
   events();
@@ -241,37 +241,37 @@ void events()
 
     XQueryKeymap(xgh.display, keys);
 
-    if(keys[7] & 64)
+    if(keys[3] & 1)
       Quit=1;
 
-    if(keys[12] & 16 && Speed < 20)
+    if(((keys[2] & 32) || (keys[10] & 64) ) && (Speed < 20))
       Speed++;
 
-    if(keys[12] & 8 && Speed > -20)
+    if( ((keys[2] & 16) || (keys[10] & 4) ) && (Speed > -20))
       Speed--;
 
     for(l=0; l<NumStars; l++)
       c[l]=b[l];
 
     XSetForeground(xgh.display,gc1,HiCol);
-    if(keys[16] &  16) {
+    if(keys[12] &  64) {
       r2+=0.02;
       XFillPolygon(xgh.display,pix,gc1,a[0],3,Convex,CoordModeOrigin);
     }
-    if(keys[16] & 128) {
+    if(keys[12] & 16) {
       r2-=0.02;
       XFillPolygon(xgh.display,pix,gc1,a[2],3,Convex,CoordModeOrigin);
     }
-    if(keys[16] &  64) {
+    if(keys[13] &  1) {
       r1+=0.02;
       XFillPolygon(xgh.display,pix,gc1,a[1],3,Convex,CoordModeOrigin);
     }
-    if(keys[16] &  32) {
+    if(keys[12] &  4) {
       r1-=0.02;
       XFillPolygon(xgh.display,pix,gc1,a[3],3,Convex,CoordModeOrigin);
     }
 
-    if(keys[16] &   2)
+    if(keys[8] &   2)
     {
       Speed=0;
       r1=r2=0; 
