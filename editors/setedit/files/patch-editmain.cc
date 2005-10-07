*** setedit/editmain.cc.orig	Thu Sep 29 15:51:43 2005
--- setedit/editmain.cc	Thu Sep 29 16:03:36 2005
***************
*** 2299,2320 ****
   else
      if (Clock)
         KillClock();
- 
-  if (UseScreenSaver && TScreen::useScreenSaver())
-    {
-     int seconds=inIdleTime/clockResolution;
-     if (seconds==screenSaverTimeMouse)
-       {
-        MouseEventType me;
-        TMouse::getEvent(me);
-        TRect r=deskTop->getExtent();
-        if (me.where.x==r.b.x-1 && me.where.y==0)
-           screenSaver();
-       }
-     else
-     if (seconds>=screenSaverTime)
-        screenSaver();
-    }
  }
  
  
--- 2299,2304 ----
