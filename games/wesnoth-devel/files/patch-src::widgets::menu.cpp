--- src/widgets/menu.cpp.orig	Thu Jan 29 22:23:06 2004
+++ src/widgets/menu.cpp	Thu Jan 29 22:23:49 2004
@@ -191,8 +191,8 @@
 			x = event.button.x;
 			y = event.button.y;
 		} else {
-			x = reinterpret_cast<int>(event.user.data1);
-			y = reinterpret_cast<int>(event.user.data2);
+			x = (int)event.user.data1;
+			y = (int)event.user.data2;
 		}
 
 		const int item = hit(x,y);
