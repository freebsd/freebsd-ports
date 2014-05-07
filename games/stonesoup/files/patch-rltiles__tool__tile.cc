--- ./rltiles/tool/tile.cc.orig	2014-04-09 17:36:33.000000000 +0200
+++ ./rltiles/tool/tile.cc	2014-05-06 21:21:37.808135615 +0200
@@ -123,10 +123,10 @@
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
