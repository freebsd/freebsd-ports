--- kspread/kspread_cell.cc.orig	Sun Feb 20 23:27:56 2005
+++ kspread/kspread_cell.cc	Sun Feb 20 23:29:21 2005
@@ -2882,7 +2882,7 @@
       x = indent + cellRect.x() + m_dTextX;
     else
       x = indent + cellRect.x() + m_dTextX
-        - ( fm.descent() + fm.ascent() ) * sin( angle * M_PI / 180 );
+        - doc->unzoomItX(( fm.descent() + fm.ascent() ) * sin( angle * M_PI / 180 ));
     double y;
     if ( angle > 0 )
       y = cellRect.y() + m_dTextY;
