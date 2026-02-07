--- src/xcwcp/application.cc.orig	2018-08-08 04:24:39 UTC
+++ src/xcwcp/application.cc
@@ -1126,6 +1126,7 @@ void Application::make_auxiliaries_end(v
 
 void Application::check_audio_system(cw_config_t *config)
 {
+#ifndef __FreeBSD__
 	if (config->audio_system == CW_AUDIO_ALSA
 	    && cw_is_pa_possible(NULL)) {
 
@@ -1137,6 +1138,7 @@ void Application::check_audio_system(cw_
 		msgBox.setText(message1 + " " + message2 + message3.arg(config->program_name).arg(config->program_name));
 		msgBox.exec();
 	}
+#endif
 
 	return;
 }
