--- ./src/interface.c.orig	2010-09-16 00:33:07.000000000 +0000
+++ ./src/interface.c	2012-09-18 15:29:36.558084978 +0000
@@ -18,6 +18,8 @@
 #include "interface.h"
 #include "support.h"
 
+extern gboolean uhf;
+
 #define GLADE_HOOKUP_OBJECT(component,widget,name) \
   gtk_object_set_data_full (GTK_OBJECT (component), name, \
     gtk_widget_ref (widget), (GtkDestroyNotify) gtk_widget_unref)
@@ -267,7 +269,7 @@
   GtkWidget *combo_entry5;
   GtkWidget *appbar1;
 
-  app1 = gnome_app_new ("Ge-x2212-2", "GE Phoenix SX X2212 EEProm programmer (VHF 16ch scan) by Lawrence Glaister VE7IT 15-Sept-2010");
+  app1 = gnome_app_new ("Ge-x2212-2", uhf?"GE Phoenix SX X2212 EEProm programmer (UHF 16ch scan) by Lawrence Glaister VE7IT 15-Sept-2010":"GE Phoenix SX X2212 EEProm programmer (VHF 16ch scan) by Lawrence Glaister VE7IT 15-Sept-2010");
 
   bonobodock1 = GNOME_APP (app1)->dock;
   gtk_widget_show (bonobodock1);
@@ -678,7 +680,7 @@
   gtk_table_attach (GTK_TABLE (table1), ch01rx, 1, 2, 1, 2,
                     (GtkAttachOptions) (0),
                     (GtkAttachOptions) (0), 2, 2);
-  gtk_entry_set_text (GTK_ENTRY (ch01rx), "146.5200");
+  gtk_entry_set_text (GTK_ENTRY (ch01rx), uhf?"446.0000":"146.5200");
   gtk_entry_set_width_chars (GTK_ENTRY (ch01rx), 9);
 
   ch02rx = gtk_entry_new ();
@@ -742,7 +744,7 @@
   gtk_table_attach (GTK_TABLE (table1), ch01tx, 3, 4, 1, 2,
                     (GtkAttachOptions) (0),
                     (GtkAttachOptions) (0), 2, 2);
-  gtk_entry_set_text (GTK_ENTRY (ch01tx), "146.5200");
+  gtk_entry_set_text (GTK_ENTRY (ch01tx), uhf?"446.0000":"146.5200");
   gtk_entry_set_width_chars (GTK_ENTRY (ch01tx), 9);
 
   ch02tx = gtk_entry_new ();
