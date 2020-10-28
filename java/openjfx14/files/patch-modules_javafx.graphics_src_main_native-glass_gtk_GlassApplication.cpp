--- modules/javafx.graphics/src/main/native-glass/gtk/GlassApplication.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-glass/gtk/GlassApplication.cpp
@@ -111,6 +111,7 @@ JNIEXPORT jint JNICALL Java_com_sun_glass_ui_gtk_GtkAp
 
     gdk_threads_enter();
     gtk_init(NULL, NULL);
+    gdk_threads_leave();
 
     return JNI_TRUE;
 }
