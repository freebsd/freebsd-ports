--- src/grip.c.orig	Sun Mar 10 21:59:44 2002
+++ src/grip.c	Wed Jul 24 01:32:08 2002
@@ -40,6 +40,12 @@
 #include "xpm.h"
 #include "parsecfg.h"
 
+#ifdef __FreeBSD__
+#define CD_POLL_SECS 15
+#else
+#define CD_POLL_SECS 1
+#endif
+
 static void ReallyDie(gint reply,gpointer data);
 static void DoHelp(GtkWidget *widget,gpointer data);
 static void MakeHelpPage(GripInfo *ginfo);
@@ -144,7 +150,7 @@
 
   app=gnome_app_new(PACKAGE,_("Grip"));
 
-  ginfo=g_new(GripInfo,1);
+  ginfo=g_new0(GripInfo,1);
 
   gtk_object_set_user_data(GTK_OBJECT(app),(gpointer)ginfo);
 
@@ -511,8 +517,10 @@
   if(ginfo->rewinding) Rewind(ginfo);
 
 #ifdef GRIPCD
-  if(!ginfo->have_disc)
-    CheckNewDisc(ginfo);
+  if (!(time(0) % CD_POLL_SECS)) {
+    if(!ginfo->have_disc)
+      CheckNewDisc(ginfo);
+  }
 
   if(ginfo->auto_eject_countdown && !(--ginfo->auto_eject_countdown))
     EjectDisc(&(ginfo->disc));
@@ -522,9 +530,10 @@
   if(ginfo->ripping|ginfo->encoding) UpdateRipProgress(ginfo);
 
   if(!ginfo->ripping) {
-    if(!ginfo->have_disc)
-      CheckNewDisc(ginfo);
-    
+    if (!(time(0) % CD_POLL_SECS)) {
+      if(!ginfo->have_disc)
+	CheckNewDisc(ginfo);
+    }
     UpdateDisplay(ginfo);
   }
 #endif
