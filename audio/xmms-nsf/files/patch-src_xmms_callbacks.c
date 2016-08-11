--- src/xmms/callbacks.c.orig	2000-07-23 10:06:43 UTC
+++ src/xmms/callbacks.c
@@ -219,7 +219,7 @@ nsf_on_ok_pressed                       
 	widget = lookup_widget(GTK_WIDGET(button), "spinbutton1");
 	nsf_cfg.play_time =  gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
 	widget = lookup_widget(GTK_WIDGET(button), "spinbutton2");
-	nsf_cfg.fadeout_time =  gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
+	nsf_cfg.silence_time =  gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
 	
 	filename = g_strconcat(g_get_home_dir(), "/.xmms/config", NULL);
 	cfg = xmms_cfg_open_file(filename);
@@ -228,7 +228,7 @@ nsf_on_ok_pressed                       
 	}
 	
 	xmms_cfg_write_int(cfg, "NSF", "play_time",nsf_cfg.play_time);
-	xmms_cfg_write_int(cfg, "NSF", "fadeout_time",nsf_cfg.fadeout_time);
+	xmms_cfg_write_int(cfg, "NSF", "silence_time",nsf_cfg.silence_time);
 	xmms_cfg_write_file(cfg, filename);
 	xmms_cfg_free(cfg);
 	g_free(filename);
