--- src/grip.c.orig	Sun Mar 10 21:59:44 2002
+++ src/grip.c	Wed May 29 21:57:19 2002
@@ -144,7 +144,7 @@
 
   app=gnome_app_new(PACKAGE,_("Grip"));
 
-  ginfo=g_new(GripInfo,1);
+  ginfo=g_new0(GripInfo,1);
 
   gtk_object_set_user_data(GTK_OBJECT(app),(gpointer)ginfo);
 
@@ -511,8 +511,10 @@
   if(ginfo->rewinding) Rewind(ginfo);
 
 #ifdef GRIPCD
-  if(!ginfo->have_disc)
-    CheckNewDisc(ginfo);
+  if (!(time(0) % 10)) {
+    if(!ginfo->have_disc)
+      CheckNewDisc(ginfo);
+  }
 
   if(ginfo->auto_eject_countdown && !(--ginfo->auto_eject_countdown))
     EjectDisc(&(ginfo->disc));
@@ -522,8 +524,10 @@
   if(ginfo->ripping|ginfo->encoding) UpdateRipProgress(ginfo);
 
   if(!ginfo->ripping) {
-    if(!ginfo->have_disc)
-      CheckNewDisc(ginfo);
+    if (!(time(0) % 10)) {
+      if(!ginfo->have_disc)
+	CheckNewDisc(ginfo);
+    }
     
     UpdateDisplay(ginfo);
   }
