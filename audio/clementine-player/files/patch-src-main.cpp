--- src/main.cpp.orig	2013-08-05 07:51:55.259557059 +0000
+++ src/main.cpp	2013-08-05 08:02:30.142556079 +0000
@@ -265,7 +265,9 @@
 #endif
 
   // This makes us show up nicely in gnome-volume-control
+#if !GLIB_CHECK_VERSION(2, 36, 0)
   g_type_init();
+#endif
   g_set_application_name(QCoreApplication::applicationName().toLocal8Bit());
 
   RegisterMetaTypes();
