--- modules/graphics/src/main/native-glass/gtk/GlassApplication.cpp.orig	2019-07-22 07:18:58 UTC
+++ modules/graphics/src/main/native-glass/gtk/GlassApplication.cpp
@@ -101,6 +101,7 @@ JNIEXPORT jint JNICALL Java_com_sun_glass_ui_gtk_GtkAp
 
     gdk_threads_enter();
     gtk_init(NULL, NULL);
+    gdk_threads_leave();
 
     return JNI_TRUE;
 }
