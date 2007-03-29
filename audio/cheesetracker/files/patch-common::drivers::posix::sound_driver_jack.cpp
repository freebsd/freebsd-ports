--- common/drivers/posix/sound_driver_jack.cpp.orig	Wed Mar 28 00:43:48 2007
+++ common/drivers/posix/sound_driver_jack.cpp	Wed Mar 28 00:44:18 2007
@@ -225,12 +225,12 @@
 
 	//printf("JACK: Connect Ports...\n");
 
-	if (jack_connect (client, jack_port_name (output_port_l), "alsa_pcm:playback_1")) {
+	if (jack_connect (client, jack_port_name (output_port_l), "oss:playback_1")) {
 		ERROR("cannot connect output ports\n");
 		//jack_client_close (client);
 		//return FUNCTION_FAILED;
 	}
-	if (jack_connect (client, jack_port_name (output_port_r), "alsa_pcm:playback_2")) {
+	if (jack_connect (client, jack_port_name (output_port_r), "oss:playback_2")) {
 		ERROR("cannot connect output ports\n");
 		//jack_client_close (client);
 		//return FUNCTION_FAILED;
