--- rate.c.orig	Fri Sep 24 11:02:14 2004
+++ rate.c	Mon Nov 22 09:44:42 2004
@@ -157,6 +157,10 @@
   struct timeval tv;
   glong dt;
 
+  gpointer data;
+  gint isamp, emitted = 0;
+  gint16 *out, *in;
+
   /* print clipping warnings at most once every second : */
   gettimeofday(&tv, NULL);
   dt = (tv.tv_sec - rc->vc.tv_last.tv_sec)  * 1000
@@ -254,9 +258,7 @@
 
 #else /* rustic resampling */
 
-  gpointer data;
-  gint isamp, emitted = 0;
-  gint16 *out, *in = *buffer;
+  in = *buffer;
 
   /* some sanity checks */
   if(length & 3) {
