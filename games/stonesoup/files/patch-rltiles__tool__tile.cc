--- ./rltiles/tool/tile.cc.orig	2013-09-30 20:32:00.000000000 +0200
+++ ./rltiles/tool/tile.cc	2013-10-11 22:07:08.178890955 +0200
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
