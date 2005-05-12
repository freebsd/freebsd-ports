--- gcin-setup-pho.c.orig	Thu May 12 09:56:35 2005
+++ gcin-setup-pho.c	Thu May 12 10:28:40 2005
@@ -42,8 +42,8 @@
   {"?¸æ????å­?", TSIN_SPACE_OPT_SELECT_CHAR},
   {"???ç·¨è¼¯?????å®?", TSIN_SPACE_OPT_FLUSH_BUFFER},
 };
-int tsin_space_optionsN = sizeof(tsin_space_options) / sizeof(tsin_space_options[0]);
 
+int tsin_space_optionsN = sizeof(tsin_space_options) / sizeof(tsin_space_options[0]);
 
 static int kbm_selN = sizeof(kbm_sel) / sizeof(kbm_sel[0]);
 
@@ -245,6 +245,16 @@
       gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
   }
 
+  GtkWidget *frame_phonetic_char_dynamic_sequence = gtk_frame_new("æ³¨é?ä¾?½¿?¨é???ª¿?´é ??");
+  gtk_box_pack_start (GTK_BOX (vbox_top), frame_phonetic_char_dynamic_sequence , TRUE, TRUE, 0);
+  gtk_container_set_border_width (GTK_CONTAINER (frame_phonetic_char_dynamic_sequence), 3);
+  check_button_phonetic_char_dynamic_sequence = gtk_check_button_new ();
+  gtk_container_add (GTK_CONTAINER (frame_phonetic_char_dynamic_sequence),
+      check_button_phonetic_char_dynamic_sequence);
+  gtk_toggle_button_set_active(
+     GTK_TOGGLE_BUTTON(check_button_phonetic_char_dynamic_sequence),
+     phonetic_char_dynamic_sequence);
+
   GtkWidget *frame_tsin_sw = gtk_frame_new("è©??è¼¸å?[ä¸?/?±]???");
   gtk_box_pack_start (GTK_BOX (vbox_top), frame_tsin_sw, TRUE, TRUE, 0);
   gtk_container_set_border_width (GTK_CONTAINER (frame_tsin_sw), 3);
@@ -306,16 +316,6 @@
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_button_phrase_pre_select),
      tsin_phrase_pre_select);
 
-
-  GtkWidget *frame_phonetic_char_dynamic_sequence = gtk_frame_new("æ³¨é?ä¾?½¿?¨é???ª¿?´é ??");
-  gtk_box_pack_start (GTK_BOX (vbox_top), frame_phonetic_char_dynamic_sequence , TRUE, TRUE, 0);
-  gtk_container_set_border_width (GTK_CONTAINER (frame_phonetic_char_dynamic_sequence), 3);
-  check_button_phonetic_char_dynamic_sequence = gtk_check_button_new ();
-  gtk_container_add (GTK_CONTAINER (frame_phonetic_char_dynamic_sequence),
-      check_button_phonetic_char_dynamic_sequence);
-  gtk_toggle_button_set_active(
-     GTK_TOGGLE_BUTTON(check_button_phonetic_char_dynamic_sequence),
-     phonetic_char_dynamic_sequence);
 
   GtkWidget *frame_tsin_disp_status_row = gtk_frame_new("è©??é¡¯ç¤º?????(è¼??è¦??)");
   gtk_box_pack_start (GTK_BOX (vbox_top), frame_tsin_disp_status_row , TRUE, TRUE, 0);
