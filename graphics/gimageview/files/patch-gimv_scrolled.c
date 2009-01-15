--- src/gimv_scrolled.c.orig	2009-01-15 19:54:26.000000000 +0100
+++ src/gimv_scrolled.c	2009-01-15 19:54:27.000000000 +0100
@@ -141,7 +141,7 @@
                       GTK_CLASS_TYPE(object_class),
                       GTK_SIGNAL_OFFSET(GimvScrolledClass, set_scroll_adjustments),
                       gtk_marshal_NONE__POINTER_POINTER,
-                      GTK_TYPE_NONE, 2, GTK_TYPE_POINTER, GTK_TYPE_POINTER);
+                      GTK_TYPE_NONE, 2, GTK_TYPE_ADJUSTMENT, GTK_TYPE_ADJUSTMENT);
     
    gimv_scrolled_signals[ADJUST_ADJUSTMENTS] = 
       gtk_signal_new ("adjust_adjustments",
