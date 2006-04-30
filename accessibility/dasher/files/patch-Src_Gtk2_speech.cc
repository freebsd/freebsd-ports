--- Src/Gtk2/speech.cc.orig	Thu Jan 12 15:52:50 2006
+++ Src/Gtk2/speech.cc	Tue Jan 17 01:29:35 2006
@@ -74,6 +74,7 @@ void setup_speech() {
 void teardown_speech() {
 
   bonobo_object_release_unref(speaker, NULL);
+  if (voices != NULL && !BONOBO_EX (&ev) && voices->_length != 0)
   CORBA_free(voices);
   GNOME_Speech_SynthesisDriver_unref(rv, &ev);
   CORBA_exception_free(&ev);
