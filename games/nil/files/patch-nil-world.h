--- nil/world.h.orig	Sat Nov 15 16:28:04 2003
+++ nil/world.h	Sat Nov 15 16:34:01 2003
@@ -34,10 +34,8 @@
   int flags;
 	union {
 		int object_id;
-		struct abspos {
-			float x_pos;
-			float y_pos;
-		};
+		float x_pos;
+		float y_pos;
 	};
 };
 
