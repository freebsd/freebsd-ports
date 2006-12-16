--- kipi-plugins/kameraklient/gpiface.cpp.orig	Sat Dec 16 15:42:30 2006
+++ kipi-plugins/kameraklient/gpiface.cpp	Sat Dec 16 15:43:57 2006
@@ -33,7 +33,7 @@
 {
 
 int GPIface::autoDetect(QString& model, QString& port) {
-    ::CameraList camList;
+    ::CameraList *camList;
     CameraAbilitiesList *abilList;
     GPPortInfoList *infoList;
     const char *camModel_, *camPort_;
@@ -41,30 +41,31 @@
 
     context = gp_context_new ();
 
+    gp_list_new (&camList);
     gp_abilities_list_new (&abilList);
     gp_abilities_list_load (abilList, context);
     gp_port_info_list_new (&infoList);
     gp_port_info_list_load (infoList);
-    gp_abilities_list_detect (abilList, infoList, &camList, context);
+    gp_abilities_list_detect (abilList, infoList, camList, context);
     gp_abilities_list_free (abilList);
     gp_port_info_list_free (infoList);
 
     gp_context_unref( context );
 
-    int count = gp_list_count (&camList);
+    int count = gp_list_count (camList);
 
     if (count<=0) {
         return -1;
     }
 
     for (int i = 0; i < count; i++) {
-        gp_list_get_name  (&camList, i, &camModel_);
-        gp_list_get_value (&camList, i, &camPort_);
+        gp_list_get_name  (camList, i, &camModel_);
+        gp_list_get_value (camList, i, &camPort_);
     }
 
     model = camModel_;
     port  = camPort_;
-
+    gp_list_unref (camList);
     return 0;
 }
 
