--- sleep_on_option.c.orig	Tue Jul 22 15:27:18 2003
+++ sleep_on_option.c	Tue Jul 22 15:27:32 2003
@@ -15,7 +15,7 @@
 
     if ( time > samples / speed ) {
       reqst.tv_sec = (time_t) floor(time);
-      reqst.tv_nsec = (long) nearbyint((time - floor(time)) * 1000000);      
+      reqst.tv_nsec = (long) rint((time - floor(time)) * 1000000);      
     } else {
       reqst.tv_sec = (time_t) floor(samples / speed);
       reqst.tv_nsec = (long) rint((samples / speed - floor(samples / speed))
