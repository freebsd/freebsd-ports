--- config.c.orig	Mon Oct 27 01:11:10 2003
+++ config.c	Mon Oct 27 01:13:25 2003
@@ -48,7 +48,7 @@
 static int mouse_sense  = CONFIG_DEF_MOUSE_SENSE;
 static int high_level   = CONFIG_DEF_HIGH_LEVEL;
 static int done         = CONFIG_DEF_DONE;
-static int nice         = CONFIG_DEF_NICE;
+static int nice1        = CONFIG_DEF_NICE;
 static int fps          = CONFIG_DEF_FPS;
 static int joy          = CONFIG_DEF_JOY;
 static int sound_vol    = CONFIG_DEF_SOUND_VOL;
@@ -166,7 +166,7 @@
                 if (strcmp(key, "audio_buff")   == 0) audio_buff   = val;
                 if (strcmp(key, "mouse_sense")  == 0) mouse_sense  = val;
                 if (strcmp(key, "high_level")   == 0) high_level   = val;
-                if (strcmp(key, "nice")         == 0) nice         = val;
+                if (strcmp(key, "nice")         == 0) nice1        = val;
                 if (strcmp(key, "done")         == 0) done         = val;
                 if (strcmp(key, "fps")          == 0) fps          = val;
                 if (strcmp(key, "joy")          == 0) joy          = val;
@@ -210,7 +210,7 @@
         fprintf(fp, "mouse_sense %d\n",  mouse_sense);
         fprintf(fp, "high_level %d\n",   high_level);
         fprintf(fp, "player %s\n",       player);
-        fprintf(fp, "nice %d\n",         nice);
+        fprintf(fp, "nice %d\n",         nice1);
         fprintf(fp, "done %d\n",         done);
         fprintf(fp, "fps %d\n",          fps);
         fprintf(fp, "joy %d\n",          joy);
@@ -242,7 +242,7 @@
 int config_sens(void) { return mouse_sense; }
 int config_high(void) { return high_level; }
 int config_done(void) { return done; }
-int config_nice(void) { return nice; }
+int config_nice(void) { return nice1; }
 int config_fps (void) { return fps; }
 int config_sound(void) { return sound_vol; }
 int config_music(void) { return music_vol; }
@@ -368,7 +368,7 @@
 
 void config_tog_nice(void)
 {
-    nice = nice ? 0 : 1;
+    nice1 = nice1 ? 0 : 1;
 }
 
 void config_tog_fps(void)
