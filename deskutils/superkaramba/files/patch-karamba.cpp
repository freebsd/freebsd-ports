--- src/karamba.cpp.orig	Sun Oct 19 22:02:45 2003
+++ src/karamba.cpp	Mon Feb  9 00:57:18 2004
@@ -2243,7 +2243,7 @@
 
 
     //Matthew Kay: set window type to "dock" (plays better with taskbar themes this way)
-    KWin::setType(winId(), NET::Dock);
+    //KWin::setType(winId(), NET::Dock);
 
     widgetMask = 0;
     info = new NETWinInfo( qt_xdisplay(), winId(), qt_xrootwin(), NET::WMState );
@@ -2662,6 +2662,26 @@
 
                 }
 
+                if( getBoolean("RIGHTBAR", line ) )
+                {
+                   int dw = QApplication::desktop()->width();
+                   move( dw - w, y );
+                   KWin::setStrut( winId(), 0, w, 0, 0 );
+                   toggleLocked->setChecked( true );
+                   slotToggleLocked();
+                   toggleLocked->setEnabled(false);
+
+                }
+		if( getBoolean("LEFTBAR", line) )
+		{
+		   int dw = QApplication::desktop()->width();
+		   move( 0, y );
+		   KWin::setStrut( winId(), w, 0, 0, 0 );
+		   toggleLocked->setChecked( true );
+		   slotToggleLocked();
+		   toggleLocked->setEnabled(false);
+
+		}
 
 		bool found = false;
                 QString path = getString( "MASK", line, found );
