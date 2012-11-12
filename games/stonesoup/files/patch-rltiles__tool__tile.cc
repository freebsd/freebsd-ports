--- ./rltiles/tool/tile.cc.orig	2012-09-30 23:25:33.000000000 +0200
+++ ./rltiles/tool/tile.cc	2012-10-27 20:49:08.845367925 +0200
@@ -125,10 +125,10 @@
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
