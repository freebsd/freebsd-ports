--- clientextras.cpp.orig	2007-08-03 15:45:28.000000000 +0200
+++ clientextras.cpp	2007-08-03 15:46:07.000000000 +0200
@@ -14,11 +14,11 @@
     int n = 3;
     float speed = 100.0f;
     float mz = d->o.z-d->eyeheight+1.55f*scale;
-    int basetime = -((int)d&0xFFF);
+    intptr_t basetime = -((intptr_t)d&0xFFF);
     if(d->state==CS_DEAD)
     {
         int r;
-        if(hellpig) { n = 2; r = range[3]; } else { n = (int)d%3; r = range[n]; };
+        if(hellpig) { n = 2; r = range[3]; } else { n = (intptr_t)d%3; r = range[n]; };
         basetime = d->lastaction;
         int t = lastmillis-d->lastaction;
         if(t<0 || t>20000) return;
