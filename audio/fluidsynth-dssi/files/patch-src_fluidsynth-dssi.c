From de62a3a1e3fc7df57e014b6c7e269d1b6195924a Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Andreas=20M=C3=BCller?= <schnitzeltony@gmail.com>
Date: Wed, 10 Oct 2018 01:00:06 +0200
Subject: [PATCH] Fix build with fluidsynth > 2.0.0
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

Signed-off-by: Andreas Müller <schnitzeltony@gmail.com>
---
 src/fluidsynth-dssi.c | 15 +++++++++++++++
  1 file changed, 15 insertions(+)

--- src/fluidsynth-dssi.c.orig	2008-11-16 17:41:35 UTC
+++ src/fluidsynth-dssi.c
@@ -167,7 +167,11 @@ fsd_get_soundfont(const char *path)
     fsd_sfont_t *sfont;
     int palloc;
     fluid_sfont_t *fluid_sfont;
+#if FLUIDSYNTH_VERSION_MAJOR < 2
     fluid_preset_t preset;
+#else
+    fluid_preset_t *preset;
+#endif
 
     /* soundfont already loaded? */
     sfont = fsd_find_loaded_soundfont(path);
@@ -206,8 +210,13 @@ fsd_get_soundfont(const char *path)
         return NULL;
     }
     fluid_sfont = fluid_synth_get_sfont_by_id(fsd_synth.fluid_synth, sfont->sfont_id);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
     fluid_sfont->iteration_start(fluid_sfont);
     while (fluid_sfont->iteration_next(fluid_sfont, &preset)) {
+#else
+    fluid_sfont_iteration_start(fluid_sfont);
+    while ((preset = fluid_sfont_iteration_next(fluid_sfont))) {
+#endif
         if (sfont->preset_count == palloc) {
             palloc *= 2;
             sfont->presets = (DSSI_Program_Descriptor *)realloc(sfont->presets,
@@ -219,9 +228,15 @@ fsd_get_soundfont(const char *path)
                 return NULL;
             }
         }
+#if FLUIDSYNTH_VERSION_MAJOR < 2
         sfont->presets[sfont->preset_count].Bank = preset.get_banknum(&preset);
         sfont->presets[sfont->preset_count].Program = preset.get_num(&preset);
         sfont->presets[sfont->preset_count].Name = preset.get_name(&preset);
+#else
+        sfont->presets[sfont->preset_count].Bank = fluid_preset_get_banknum(preset);
+        sfont->presets[sfont->preset_count].Program = fluid_preset_get_num(preset);
+        sfont->presets[sfont->preset_count].Name = fluid_preset_get_name(preset);
+#endif
         sfont->preset_count++;
     }
 
