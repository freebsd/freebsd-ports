--- Src/Gtk2/speech.cc.orig	Fri Nov 12 13:11:45 2004
+++ Src/Gtk2/speech.cc	Fri Nov 12 13:11:59 2004
@@ -46,7 +46,7 @@
 
   voices = GNOME_Speech_SynthesisDriver_getAllVoices (rv, &ev);
 
-  if (voices==NULL || BONOBO_EX (&ev)) {
+  if (voices==NULL || voices->_buffer==NULL || BONOBO_EX (&ev)) {
     printf(_("Unable to initialize voices"));
     speaker=NULL;
     return;
