$FreeBSD$

--- src/m_glob.c.orig	Sun Mar 25 00:37:25 2007
+++ src/m_glob.c	Sun Mar 25 00:38:40 2007
@@ -21,9 +21,9 @@
 void glob_audio_properties(t_pd *dummy, t_floatarg flongform);
 void glob_audio_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
 void glob_audio_setapi(t_pd *dummy, t_floatarg f);
-void glob_midi_properties(t_pd *dummy, t_floatarg flongform);
-void glob_midi_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
-void glob_midi_setapi(t_pd *dummy, t_floatarg f);
+//void glob_midi_properties(t_pd *dummy, t_floatarg flongform);
+//void glob_midi_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
+//void glob_midi_setapi(t_pd *dummy, t_floatarg f);
 void glob_start_path_dialog(t_pd *dummy, t_floatarg flongform);
 void glob_path_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
 void glob_start_startup_dialog(t_pd *dummy, t_floatarg flongform);
@@ -96,12 +96,12 @@
         gensym("audio-dialog"), A_GIMME, 0);
     class_addmethod(glob_pdobject, (t_method)glob_audio_setapi,
         gensym("audio-setapi"), A_FLOAT, 0);
-    class_addmethod(glob_pdobject, (t_method)glob_midi_setapi,
-        gensym("midi-setapi"), A_FLOAT, 0);
-    class_addmethod(glob_pdobject, (t_method)glob_midi_properties,
-        gensym("midi-properties"), A_DEFFLOAT, 0);
-    class_addmethod(glob_pdobject, (t_method)glob_midi_dialog,
-        gensym("midi-dialog"), A_GIMME, 0);
+    //    class_addmethod(glob_pdobject, (t_method)glob_midi_setapi,
+    //        gensym("midi-setapi"), A_FLOAT, 0);
+    //    class_addmethod(glob_pdobject, (t_method)glob_midi_properties,
+    //        gensym("midi-properties"), A_DEFFLOAT, 0);
+    //    class_addmethod(glob_pdobject, (t_method)glob_midi_dialog,
+    //        gensym("midi-dialog"), A_GIMME, 0);
     class_addmethod(glob_pdobject, (t_method)glob_start_path_dialog,
         gensym("start-path-dialog"), 0);
     class_addmethod(glob_pdobject, (t_method)glob_path_dialog,
