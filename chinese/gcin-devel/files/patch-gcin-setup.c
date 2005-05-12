--- gcin-setup.c.orig	Thu May 12 14:38:04 2005
+++ gcin-setup.c	Thu May 12 14:39:09 2005
@@ -609,22 +609,21 @@
   GtkWidget *vbox = gtk_vbox_new (FALSE, 0);
   gtk_container_add (GTK_CONTAINER (main_window), vbox);
 
-  GtkWidget *button_kbm = gtk_button_new_with_label("gcin 注音/詞音設定");
-  gtk_box_pack_start (GTK_BOX (vbox), button_kbm, TRUE, TRUE, 0);
-  g_signal_connect (G_OBJECT (button_kbm), "clicked",
-                    G_CALLBACK (cb_kbm), NULL);
-
   GtkWidget *button_appearance_conf = gtk_button_new_with_label("外觀設定");
   gtk_box_pack_start (GTK_BOX (vbox), button_appearance_conf, TRUE, TRUE, 0);
   g_signal_connect (G_OBJECT (button_appearance_conf), "clicked",
                     G_CALLBACK (cb_appearance_conf), NULL);
 
+  GtkWidget *button_kbm = gtk_button_new_with_label("gcin 注音/詞音設定");
+  gtk_box_pack_start (GTK_BOX (vbox), button_kbm, TRUE, TRUE, 0);
+  g_signal_connect (G_OBJECT (button_kbm), "clicked",
+                    G_CALLBACK (cb_kbm), NULL);
+
   GtkWidget *button_gtab_conf = gtk_button_new_with_label("倉頡/行列/嘸蝦米/大易設定");
   gtk_box_pack_start (GTK_BOX (vbox), button_gtab_conf, TRUE, TRUE, 0);
   g_signal_connect (G_OBJECT (button_gtab_conf), "clicked",
                     G_CALLBACK (cb_gtab_conf), NULL);
 
-
   GtkWidget *button_default_input_method = gtk_button_new_with_label("內定輸入法 & 開啟/關閉");
   gtk_box_pack_start (GTK_BOX (vbox), button_default_input_method, TRUE, TRUE, 0);
   g_signal_connect (G_OBJECT (button_default_input_method), "clicked",
@@ -655,7 +654,7 @@
   g_signal_connect (G_OBJECT (button_ts_import_sys), "clicked",
                     G_CALLBACK (cb_ts_import_sys), NULL);
 
-  GtkWidget *button_alt_shift = gtk_button_new_with_label("alt-shift 片語編輯");
+  GtkWidget *button_alt_shift = gtk_button_new_with_label("Alt-Shift 片語編輯");
   gtk_box_pack_start (GTK_BOX (vbox), button_alt_shift, TRUE, TRUE, 0);
   g_signal_connect (G_OBJECT (button_alt_shift), "clicked",
                     G_CALLBACK (cb_alt_shift), NULL);
