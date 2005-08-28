--- Src/Gtk2/speech.cc.orig	Fri Aug 19 09:57:44 2005
+++ Src/Gtk2/speech.cc	Mon Aug 22 20:23:21 2005
@@ -78,7 +78,8 @@ void setup_speech() {
 void teardown_speech() {
 
   bonobo_object_release_unref (speaker, NULL);
-  CORBA_free (voices);
+  if (voices != NULL && !BONOBO_EX (&ev) && voices->_length != 0)
+      CORBA_free (voices);
   GNOME_Speech_SynthesisDriver_unref(rv, &ev);
   CORBA_exception_free (&ev);
 
