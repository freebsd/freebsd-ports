--- sleep_on_option.c.orig	2006-01-05 17:36:27 UTC
+++ sleep_on_option.c
@@ -15,7 +15,7 @@ void sleep_on_option(double time, double
 
     if ( time > samples / speed ) {
       reqst.tv_sec = (time_t) floor(time);
-      reqst.tv_nsec = (long) nearbyint((time - floor(time)) * 1000000);      
+      reqst.tv_nsec = (long) rint((time - floor(time)) * 1000000);      
     } else {
       reqst.tv_sec = (time_t) floor(samples / speed);
       reqst.tv_nsec = (long) rint((samples / speed - floor(samples / speed))
