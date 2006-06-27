--- bl.c.orig	Sat Feb  4 20:13:23 2006
+++ bl.c	Tue Jun 27 02:07:43 2006
@@ -452,6 +452,8 @@
   int i ;
   XEvent event ;
 
+  double fps;
+
   fprintf(stderr,"THIS TEST WILL TAKE SOME TIME\n") ;
 
   blo->opt.wx = blo->opt.wy = blo->opt.wz = 6 ;
@@ -485,7 +487,7 @@
     }
   gettimeofday(&currenttime, &tz) ;
 
-  double fps = (1000000. * i )
+  fps = (1000000. * i )
 	       / ( (currenttime.tv_sec - starttime.tv_sec)*1000000
 	       +  currenttime.tv_usec - starttime.tv_usec ) ;
   printf("%.2f frames/sec buffering=%d %s clearline=%d\n",
