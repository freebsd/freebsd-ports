--- src/pointer.h.orig	Sat Jan  1 14:55:27 2005
+++ src/pointer.h	Sat Jan  1 14:56:09 2005
@@ -45,9 +45,9 @@
 
     inline void setRow(int row);
     inline void setColumn(int column);
-    inline void setRowColumn(int row, int column);
-    inline void setMoved(bool flag);
-    inline bool moved();
+    void setRowColumn(int row, int column);
+    void setMoved(bool flag);
+    bool moved();
 
     Str * image_name;
     Image * ima;
