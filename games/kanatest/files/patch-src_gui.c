--- src/gui.c.orig	2020-06-11 10:29:04 UTC
+++ src/gui.c
@@ -1129,40 +1129,40 @@ HildonGtkInputMode input_mode;
 #ifdef MAEMO
      gtk_container_add (GTK_CONTAINER (hbuttonbox), appGUI->reverse_button);
      gtk_container_set_border_width (GTK_CONTAINER (appGUI->reverse_button), 4);
-     GTK_WIDGET_SET_FLAGS (appGUI->reverse_button, GTK_CAN_DEFAULT);
+     gtk_widget_set_can_default (appGUI->reverse_button, TRUE);
     
      gtk_container_add (GTK_CONTAINER (hbuttonbox), appGUI->stat_button);
      gtk_container_set_border_width (GTK_CONTAINER (appGUI->stat_button), 4);
-     GTK_WIDGET_SET_FLAGS (appGUI->stat_button, GTK_CAN_DEFAULT);
+     gtk_widget_set_can_default (appGUI->stat_button, TRUE);
 
      appGUI->chart_button = gui_stock_label_button(NULL, KANATEST_STOCK_BUTTON_CHART);
-     GTK_WIDGET_UNSET_FLAGS (appGUI->chart_button, GTK_CAN_FOCUS);
+     gtk_widget_set_can_focus (appGUI->chart_button, FALSE);
      g_signal_connect (G_OBJECT (appGUI->chart_button), "clicked",
                          G_CALLBACK (show_chart_window_cb), appGUI);
      gtk_widget_show (appGUI->chart_button);
      gtk_container_add (GTK_CONTAINER (hbuttonbox), appGUI->chart_button);
      gtk_container_set_border_width (GTK_CONTAINER (appGUI->chart_button), 4);
-     GTK_WIDGET_SET_FLAGS (appGUI->chart_button, GTK_CAN_DEFAULT);
+     gtk_widget_set_can_default (appGUI->chart_button, TRUE);
      gtk_widget_set_tooltip_text (appGUI->chart_button, _("Kana chart"));
 
      appGUI->prefs_button = gui_stock_label_button(NULL, KANATEST_STOCK_BUTTON_OPTIONS);
-     GTK_WIDGET_UNSET_FLAGS (appGUI->prefs_button, GTK_CAN_FOCUS);
+     gtk_widget_set_can_focus (appGUI->prefs_button, FALSE);
      g_signal_connect (G_OBJECT (appGUI->prefs_button), "clicked",
                          G_CALLBACK (show_options_window_cb), appGUI);
      gtk_widget_show (appGUI->prefs_button);
      gtk_container_add (GTK_CONTAINER (hbuttonbox), appGUI->prefs_button);
      gtk_container_set_border_width (GTK_CONTAINER (appGUI->prefs_button), 4);
-     GTK_WIDGET_SET_FLAGS (appGUI->prefs_button, GTK_CAN_DEFAULT);
+     gtk_widget_set_can_default (appGUI->prefs_button, TRUE);
      gtk_widget_set_tooltip_text (appGUI->prefs_button, _("Options"));
 
      appGUI->about_button = gui_stock_label_button(NULL, KANATEST_STOCK_BUTTON_ABOUT);
-     GTK_WIDGET_UNSET_FLAGS (appGUI->about_button, GTK_CAN_FOCUS);
+     gtk_widget_set_can_focus (appGUI->about_button, FALSE);
      g_signal_connect (G_OBJECT (appGUI->about_button), "clicked",
                          G_CALLBACK (show_about_window_cb), appGUI);
      gtk_widget_show (appGUI->about_button);
      gtk_container_add (GTK_CONTAINER (hbuttonbox), appGUI->about_button);
      gtk_container_set_border_width (GTK_CONTAINER (appGUI->about_button), 4);
-     GTK_WIDGET_SET_FLAGS (appGUI->about_button, GTK_CAN_DEFAULT);
+     gtk_widget_set_can_default (appGUI->about_button, TRUE);
 
      gtk_widget_set_tooltip_text (appGUI->about_button, _("About"));
 #endif
