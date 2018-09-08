MainWindow.cpp:157:33: error: C-style cast from 'nullptr_t' to 'GtkAccelFlags' is not allowed
                                (GtkAccelFlags)NULL, closure);
                                ^~~~~~~~~~~~~~~~~~~

--- src/MainWindow.cpp.orig	2018-08-25 04:31:20 UTC
+++ src/MainWindow.cpp
@@ -154,7 +154,7 @@ MainWindow::MainWindow()
         closure = g_cclosure_new(G_CALLBACK(keys[key].func), (gpointer)this, NULL);
         gtk_accel_group_connect(accelerators, keys[key].key,
                                 (GdkModifierType)keys[key].modifier,
-                                (GtkAccelFlags)NULL, closure);
+                                (GtkAccelFlags)0, closure);
         g_closure_unref(closure);
     }
 
