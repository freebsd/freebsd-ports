--- src/mixxx.h.orig	Fri Jun 25 21:13:01 2004
+++ src/mixxx.h	Fri Jun 25 21:13:29 2004
@@ -96,6 +96,7 @@
     /** Change of file to play */
     //void slotChangePlay(int,int,int, const QPoint &);
   private:
+    void Timeout();
     /** view is the main widget which represents your working area. The View
      * class should handle all events of the view widget.  It is kept empty so
      * you can create your view according to your application's needs by
