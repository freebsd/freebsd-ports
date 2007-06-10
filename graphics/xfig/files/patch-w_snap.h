--- w_snap.h.orig	Tue Nov  9 13:14:42 2004
+++ w_snap.h
@@ -63,7 +63,7 @@
 extern Widget snap_indicator_panel;  
 extern Widget snap_indicator_label;
 
-#  define signbit(x) \
+#  define signbit_(x) \
     ((0.0 >  (x)) ? 1 : 0)
 
 
