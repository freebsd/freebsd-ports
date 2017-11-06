--- modules/graphics/src/main/native-glass/gtk/glass_general.cpp.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-glass/gtk/glass_general.cpp
@@ -372,6 +372,7 @@ JNI_OnLoad(JavaVM *jvm, void *reserved)
 
     gdk_threads_enter();
     gtk_init(NULL, NULL);
+    gdk_threads_leave();
 
     return JNI_VERSION_1_6;
 }
