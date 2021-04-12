Fix forgotten renamed variable.

--- mpv_qt4.cpp.orig	2021-04-06 20:21:29 UTC
+++ mpv_qt4.cpp
@@ -518,7 +518,7 @@ static mpdm_t qt4_drv_idle(mpdm_t a, mpdm_t ctxt)
 
     window->area->timer->stop();
 
-    if (msecs)
+    if (idle_msecs)
         window->area->timer->start(idle_msecs);
 
     return NULL;
