--- ./src/xmms/nsf.c.orig	Sun Jan  7 06:15:12 2001
+++ ./src/xmms/nsf.c	Wed Jan 10 20:13:26 2007
@@ -23,7 +23,8 @@
 
 #define VERSION  "0.0.3"
 #define PLAYTIME 30
-#define FADEOUTTIME 5
+#define SILENCETIME 5
+#define FREQ 44100
 
 #include "nsf.h"
 
@@ -328,7 +329,7 @@
 		widget = lookup_widget(nsf_configure_win, "spinbutton1");
 		gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget), nsf_cfg.play_time);
 		widget = lookup_widget(nsf_configure_win, "spinbutton2");
-		gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget), nsf_cfg.fadeout_time);
+		gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget), nsf_cfg.silence_time);
 
 		gtk_widget_show(nsf_configure_win);
 	}else{
@@ -357,7 +358,7 @@
 	nsf_win->dock_window_list = NULL;
 	
 	nsf_cfg.play_time = PLAYTIME;	         /* second */
-	nsf_cfg.fadeout_time = FADEOUTTIME;      /* second */
+	nsf_cfg.silence_time = SILENCETIME;      /* second */
 	nsf_cfg.player_shaded = FALSE;
 	nsf_cfg.easy_move = FALSE;
 	
@@ -365,7 +366,7 @@
 	
 	if ((cfg = xmms_cfg_open_file(filename)) != 0){
 		xmms_cfg_read_int(cfg, "NSF", "play_time", &nsf_cfg.play_time);
-		xmms_cfg_read_int(cfg, "NSF", "fadeout_time", &nsf_cfg.fadeout_time);
+		xmms_cfg_read_int(cfg, "NSF", "silence_time", &nsf_cfg.silence_time);
 		xmms_cfg_free(cfg);
 	}
 }
@@ -439,10 +440,11 @@
 {
 	char data[2048 * 2];
 	int bytes, blk_size, rate;
+	Uint32 c = 0, count = 0;
 	
 	//setting NSF
 	NSFSetSongNo(nsf_file->current_song);
-	NESAudioFrequencySet(44100);
+	NESAudioFrequencySet(FREQ);
 	NESReset();
 	
 	//16bit/8bit * 1channel * 512 sample = 1024byte
@@ -460,7 +462,15 @@
 				}
 				if (bytes > 0){
 					//read 1024byte = 512 sample * 2byte
-					NESAudioRender(data, bytes/2);
+					c = NESAudioRender((Int16*)data, bytes/2);
+					if (c < 512)
+						count = 0;
+					else
+						count += c;
+					if (count > FREQ*nsf_cfg.silence_time) {
+						nsf_file->eos = 1;
+						count = 0;
+					}
 					nsf_ip.add_vis_pcm(nsf_ip.output->written_time(), (nsf_file->bits_per_sample == 16) ? FMT_S16_LE : FMT_U8,
 							   nsf_file->channels, bytes, data);
 					
@@ -512,11 +522,14 @@
 	if (!(nsf_file->file = fopen(filename, "rb"))){
 		return;
 	}
+
+	nsf_about();
+	
 	fseek(nsf_file->file, 0, SEEK_END);
 	count = ftell(nsf_file->file);
 	fseek(nsf_file->file, 0, SEEK_SET);
 	
-	(void*)buffer = g_malloc0(count);
+	buffer = (void*)g_malloc0(count);
 	for(i=0;i<count;i++){
 		*(buffer+i) = fgetc(nsf_file->file);
 	}
