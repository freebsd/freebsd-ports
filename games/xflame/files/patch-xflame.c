--- xflame.c.orig	1998-12-16 15:28:03.000000000 +0800
+++ xflame.c	2011-09-05 14:57:44.000000000 +0800
@@ -28,6 +28,8 @@
 
 /* INCLUDES! */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -452,18 +454,18 @@ int SetupXImage(struct globaldata *g,int
   /*to the window, to speedup drawing, and give us Double Buffering */
   int hbits,hs;
   int imsize;
-  unsigned char *im;  
+  unsigned char *im;
   
   hbits=powerof(w);
   hs=(1<<hbits);
   /* calculate the memory needed for the image data */
   imsize=hs*h*g->depth;
   /* allocate the memory for the image data */
-  im=(char *)malloc(imsize);
+  im=(unsigned char *)malloc(imsize);
   /* if we couldn't allocate the memory, return 0 */
   if (!im) return 0;
   /* create the XImage from the data */
-  g->xim=XCreateImage(g->disp,g->vis,g->depth,ZPixmap,0,im,hs,h,32,0);
+  g->xim=XCreateImage(g->disp,g->vis,g->depth,ZPixmap,0,(char *)im,hs,h,32,0);
   g->im=im;
   g->ims=hbits;
   XMapWindow(g->disp,g->win);
@@ -881,7 +883,7 @@ int Xflame(struct globaldata *g,int w, i
 }
 
 /* Here's the MAIN part of the program */
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   struct globaldata glob;
   char disp[256],colorspec[256],title[80];
