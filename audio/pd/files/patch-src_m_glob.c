$FreeBSD$

--- src/m_glob.c.orig	Thu Jul 31 20:48:15 2003
+++ src/m_glob.c	Tue Nov 11 22:43:27 2003
@@ -21,8 +21,8 @@ void glob_finderror(t_pd *dummy);
 void glob_audio_properties(t_pd *dummy, t_floatarg flongform);
 void glob_audio_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
 void glob_audio_setapi(t_pd *dummy, t_floatarg f);
-void glob_midi_properties(t_pd *dummy, t_floatarg flongform);
-void glob_midi_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
+//void glob_midi_properties(t_pd *dummy, t_floatarg flongform);
+//void glob_midi_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
 void glob_start_path_dialog(t_pd *dummy, t_floatarg flongform);
 void glob_path_dialog(t_pd *dummy, t_symbol *s, int argc, t_atom *argv);
 void glob_ping(t_pd *dummy);
@@ -89,10 +89,10 @@ void glob_init(void)
     	gensym("audio-dialog"), A_GIMME, 0);
     class_addmethod(glob_pdobject, (t_method)glob_audio_setapi,
     	gensym("audio-setapi"), A_FLOAT, 0);
-    class_addmethod(glob_pdobject, (t_method)glob_midi_properties,
-    	gensym("midi-properties"), A_DEFFLOAT, 0);
-    class_addmethod(glob_pdobject, (t_method)glob_midi_dialog,
-    	gensym("midi-dialog"), A_GIMME, 0);
+//    class_addmethod(glob_pdobject, (t_method)glob_midi_properties,
+//    	gensym("midi-properties"), A_DEFFLOAT, 0);
+//    class_addmethod(glob_pdobject, (t_method)glob_midi_dialog,
+//    	gensym("midi-dialog"), A_GIMME, 0);
     class_addmethod(glob_pdobject, (t_method)glob_start_path_dialog,
     	gensym("start-path-dialog"), A_DEFFLOAT, 0);
     class_addmethod(glob_pdobject, (t_method)glob_path_dialog,
