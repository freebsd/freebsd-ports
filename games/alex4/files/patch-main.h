--- main.h.orig	2016-06-14 13:49:42.882747000 -0400
+++ main.h
@@ -93,5 +93,8 @@
 #define check_bb_collision(x1,y1,w1,h1,x2,y2,w2,h2) (!( ((x1)>=(x2)+(w2)) || ((x2)>=(x1)+(w1)) || \
                                                         ((y1)>=(y2)+(h2)) || ((y2)>=(y1)+(h1)) ))
 
+#ifndef DATADIR
+#define DATADIR "data/"
+#endif
 
 #endif
