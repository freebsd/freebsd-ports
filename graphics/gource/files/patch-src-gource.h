--- src/gource.h.orig	2009-11-25 05:29:14.000000000 +0300
+++ src/gource.h	2009-11-27 12:35:43.000000000 +0300
@@ -110,7 +110,7 @@ class Gource : public SDLApp {
     int framecount;
 
     float runtime;
-    long  currtime;
+    time_t  currtime;
     float subseconds;
 
     float splash;
