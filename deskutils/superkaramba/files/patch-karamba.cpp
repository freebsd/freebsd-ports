--- src/karamba.cpp.orig	2003-11-07 01:15:20.000000000 -0500
+++ src/karamba.cpp	2003-11-07 02:30:39.000000000 -0500
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
