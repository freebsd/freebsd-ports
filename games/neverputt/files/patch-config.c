--- config.c.orig	Mon Oct 27 02:06:05 2003
+++ config.c	Mon Oct 27 02:08:21 2003
@@ -46,7 +46,7 @@
 static int audio_rate   = CONFIG_DEF_AUDIO_RATE;
 static int audio_buff   = CONFIG_DEF_AUDIO_BUFF;
 static int mouse_sense  = CONFIG_DEF_MOUSE_SENSE;
-static int nice         = CONFIG_DEF_NICE;
+static int nice1         = CONFIG_DEF_NICE;
 static int fps          = CONFIG_DEF_FPS;
 static int sound_vol    = CONFIG_DEF_SOUND_VOL;
 static int music_vol    = CONFIG_DEF_MUSIC_VOL;
@@ -152,7 +152,7 @@
                 if (strcmp(key, "audio_rate")   == 0) audio_rate   = val;
                 if (strcmp(key, "audio_buff")   == 0) audio_buff   = val;
                 if (strcmp(key, "mouse_sense")  == 0) mouse_sense  = val;
-                if (strcmp(key, "nice")         == 0) nice         = val;
+                if (strcmp(key, "nice")         == 0) nice1        = val;
                 if (strcmp(key, "fps")          == 0) fps          = val;
                 if (strcmp(key, "sound_vol")    == 0) sound_vol    = val;
                 if (strcmp(key, "music_vol")    == 0) music_vol    = val;
@@ -178,7 +178,7 @@
         fprintf(fp, "audio_rate %d\n",   audio_rate);
         fprintf(fp, "audio_buff %d\n",   audio_buff);
         fprintf(fp, "mouse_sense %d\n",  mouse_sense);
-        fprintf(fp, "nice %d\n",         nice);
+        fprintf(fp, "nice %d\n",         nice1);
         fprintf(fp, "fps %d\n",          fps);
         fprintf(fp, "sound_vol %d\n",    sound_vol);
         fprintf(fp, "music_vol %d\n",    music_vol);
@@ -198,7 +198,7 @@
 int config_rate(void) { return audio_rate; }
 int config_buff(void) { return audio_buff; }
 int config_sens(void) { return mouse_sense; }
-int config_nice(void) { return nice; }
+int config_nice(void) { return nice1; }
 int config_fps (void) { return fps; }
 int config_sound(void) { return sound_vol; }
 int config_music(void) { return music_vol; }
@@ -305,7 +305,7 @@
 
 void config_tog_nice(void)
 {
-    nice = nice ? 0 : 1;
+    nice1 = nice1 ? 0 : 1;
 }
 
 void config_tog_fps(void)
