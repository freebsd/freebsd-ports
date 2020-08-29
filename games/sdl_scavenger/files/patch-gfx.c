--- gfx.c.orig	2020-08-29 13:07:52 UTC
+++ gfx.c
@@ -21,7 +21,8 @@ unsigned char mustlock=0,locked=0;
 unsigned char blackcolor,whitecolor;
 
 int pressedcodes[KEYMAX],downcodes[KEYMAX],numpressed=0,numdown=0;
-int mousex,mousey,mouseb,mousebd;
+extern int mousex,mousey;
+int mouseb,mousebd;
 
 unsigned char mymap[768],currentmap[768];
 
