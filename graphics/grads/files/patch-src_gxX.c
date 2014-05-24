--- src/gxX.c.orig	2014-05-24 15:32:45.000000000 -0700
+++ src/gxX.c	2014-05-24 15:43:22.000000000 -0700
@@ -701,7 +701,7 @@
   XStandardColormap best;
   int screen_num = DefaultScreen(display);
 		
-  if (clr<16 || clr>99) return;
+  if (clr<16 || clr>99) return 1;
   if (cused[clr]) {
      XFreeColors(display, cmap, &(cvals[clr]),1,0);
      cused[clr]=0;
@@ -864,6 +864,7 @@
   return;
 }
 
+void
 dump_back_buffer(filename) /* hoop */
     char *filename ; /* hoop */
 { /* hoop */
@@ -883,6 +884,7 @@
     } /* hoop */
 } /* hoop */
 
+void
 dump_front_buffer(filename) /* hoop */
     char *filename ; /* hoop */
 { /* hoop */
@@ -2296,17 +2298,17 @@
   pch = (char *)malloc(512);
   if (pch==NULL) {
     printf ("Memory Allocation Error: Dialog Box\n");
-    return;
+    return '\0';
   }
   tch = (char *)malloc(512);
   if (tch==NULL) {
     printf ("Memory Allocation Error: Dialog Box\n");
-    return;
+    return '\0';
   }
   rch = (char *)malloc(512);
   if (rch==NULL) {
     printf ("Memory Allocation Error: Dialog Box\n");
-    return;
+    return '\0';
   }
   plen = 0;
   rlen = 0;
