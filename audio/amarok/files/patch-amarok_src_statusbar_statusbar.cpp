--- amarok/src/statusbar/statusbar.cpp.orig	Mon Dec 18 00:17:13 2006
+++ amarok/src/statusbar/statusbar.cpp	Mon Dec 18 00:13:27 2006
@@ -81,7 +81,7 @@
     m_slider->setMinimumWidth( m_timeLabel->width() );
 
     m_timeLabel2 = new TimeLabel( positionBox );
-    m_slider->setMinimumWidth( m_timeLabel2->width() );
+    m_slider->setMinimumWidth( m_timeLabel2->width() + 128 );
 
 
     // TODO Both labels need tooltips (string freeze?)
