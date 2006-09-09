--- hfterm/src/helpgui.c.orig	Mon Jul 31 15:51:44 2006
+++ hfterm/src/helpgui.c	Mon Jul 31 15:55:24 2006
@@ -426,7 +426,12 @@
   gtk_container_add (GTK_CONTAINER (scrw_help_4), text_help_4);
   gtk_tooltips_set_tip (tooltips, text_help_4, _("Left Side English \nRight Side German"), NULL);
   gtk_text_set_editable (GTK_TEXT (text_help_4), FALSE);
+#ifdef __linux__
   textinsert("/usr/share/hf/HF-HOWTO.txt", GTK_TEXT(text_help_4));
+#endif
+#ifdef __FreeBSD
+  textinsert("/usr/local/share/hf/HF-HOWTO.txt", GTK_TEXT(text_help_4));
+#endif
 
   label_help_4 = gtk_label_new (_("HF-HOWTO"));
   gtk_widget_set_name (label_help_4, "label_help_4");
@@ -509,8 +514,12 @@
   gtk_container_add (GTK_CONTAINER (scrw_help_6), text_help_6);
   gtk_tooltips_set_tip (tooltips, text_help_6, _("Left Side English \nRight Side German"), NULL);
   gtk_text_set_editable (GTK_TEXT (text_help_6), FALSE);
+#ifdef __linux__
   textinsert("/usr/share/hf/DE-HF-HOWTO.txt", GTK_TEXT(text_help_6));
-
+#endif
+#ifdef __FreeBSD__
+  textinsert("/usr/local/share/hf/DE-HF-HOWTO.txt", GTK_TEXT(text_help_6));
+#endif
   label_help_6 = gtk_label_new (_("DE-HF-HOWTO"));
   gtk_widget_set_name (label_help_6, "label_help_6");
   gtk_widget_ref (label_help_6);
@@ -589,8 +598,12 @@
   gtk_container_add (GTK_CONTAINER (scrw_help_8), text_help_8);
   gtk_tooltips_set_tip (tooltips, text_help_8, _("This mailbox list is provided monthly, \nyou can subscribe it via e-mail or packet.\n"), NULL);
   gtk_text_set_editable (GTK_TEXT (text_help_8), FALSE);
+#ifdef __linux__
   textinsert("/usr/share/hf/P-MB-list.txt", GTK_TEXT(text_help_8));
-
+#endif
+#ifdef __FreeBSD__
+  textinsert("/usr/local/share/hf/P-MB-list.txt", GTK_TEXT(text_help_8));
+#endif
   label_help_8 = gtk_label_new (_("Pactor Mailbox List"));
   gtk_widget_set_name (label_help_8, "label_help_8");
   gtk_widget_ref (label_help_8);
@@ -629,8 +642,12 @@
   gtk_container_add (GTK_CONTAINER (scrw_help_9), text_help_9);
   gtk_tooltips_set_tip (tooltips, text_help_9, _("Left Side English \nRight German"), NULL);
   gtk_text_set_editable (GTK_TEXT (text_help_9), FALSE);
+#ifdef __linux__
   textinsert("/usr/share/hf/pactor.txt", GTK_TEXT(text_help_9));
-
+#endif
+#ifdef __FreeBSD__
+  textinsert("/usr/local/share/hf/pactor.txt", GTK_TEXT(text_help_9));
+#endif
   label_help_9 = gtk_label_new (_("PACTOR spec"));
   gtk_widget_set_name (label_help_9, "label_help_9");
   gtk_widget_ref (label_help_9);
