--- setedit/editmain.cc.orig	2004-10-18 09:38:28.000000000 -0700
+++ setedit/editmain.cc	2010-06-10 01:14:22.000000000 -0700
@@ -2299,22 +2299,6 @@
  else
     if (Clock)
        KillClock();
-
- if (UseScreenSaver && TScreen::useScreenSaver())
-   {
-    int seconds=inIdleTime/clockResolution;
-    if (seconds==screenSaverTimeMouse)
-      {
-       MouseEventType me;
-       TMouse::getEvent(me);
-       TRect r=deskTop->getExtent();
-       if (me.where.x==r.b.x-1 && me.where.y==0)
-          screenSaver();
-      }
-    else
-    if (seconds>=screenSaverTime)
-       screenSaver();
-   }
 }
 
 
