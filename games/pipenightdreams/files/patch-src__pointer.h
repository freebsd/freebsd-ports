--- ./src/pointer.h.orig	2002-01-17 20:56:41.000000000 +0100
+++ ./src/pointer.h	2014-02-01 23:41:06.000000000 +0100
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
