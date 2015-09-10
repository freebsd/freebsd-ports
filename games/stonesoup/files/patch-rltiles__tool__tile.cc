--- rltiles/tool/tile.cc.orig	2015-03-04 04:53:29 UTC
+++ rltiles/tool/tile.cc
@@ -123,10 +123,10 @@ void tile::add_rim(const tile_colour &ri
             if (flags[x + y * m_width])
                 continue;
 
-            if (x > 0 && flags[(x-1) + y * m_width]
-                || y > 0 && flags[x + (y-1) * m_width]
-                || x < m_width - 1 && flags[(x+1) + y * m_width]
-                || y < m_height - 1 && flags[x + (y+1) * m_width])
+            if ((x > 0 && flags[(x-1) + y * m_width])
+                || (y > 0 && flags[x + (y-1) * m_width])
+                || (x < m_width - 1 && flags[(x+1) + y * m_width])
+                || (y < m_height - 1 && flags[x + (y+1) * m_width]))
             {
                 get_pixel(x,y) = rim;
             }
