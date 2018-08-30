--- korganizer/kodaymatrix.cpp.orig	2018-08-30 09:44:00 UTC
+++ korganizer/kodaymatrix.cpp
@@ -862,7 +862,7 @@ void KODayMatrix::paintEvent( QPaintEven
       p.setPen( actcol );
     }
     // reset bold font to plain font
-    if ( mEvents.contains( mDays[i] ) > 0 ) {
+    if ( mEvents.contains( mDays[i] ) ) {
       QFont myFont = font();
       myFont.setBold( false );
       p.setFont( myFont );
