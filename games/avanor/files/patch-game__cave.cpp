--- ./game/cave.cpp.orig	2013-10-30 01:23:52.000000000 -0200
+++ ./game/cave.cpp	2013-10-30 01:25:33.000000000 -0200
@@ -192,7 +192,8 @@
 		}
 	
 	}
-	r.Setup(&XRect(x, y, x + l, y + h));
+	XRect xrecttemp = XRect(x, y, x + l, y + h);
+	r.Setup(&xrecttemp);
 }
 
 int XCave::Compare(XObject * o)
