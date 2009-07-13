--- common/source/linux/MGTreeTooltip.h.orig	2009-07-07 17:08:50.000000000 +0200
+++ common/source/linux/MGTreeTooltip.h	2009-07-07 17:09:06.000000000 +0200
@@ -39,7 +39,7 @@
     
     WillShowSignal _show_signal;
     
-    SigC::Connection _timeout;
+    sigc::connection _timeout;
 
     void expose_event(GdkEventExpose *event);
     void leave_event(GdkEventCrossing *event);
