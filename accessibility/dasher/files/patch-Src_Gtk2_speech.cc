--- Src/Gtk2/speech.cc.orig	Fri Jul 30 15:28:41 2004
+++ Src/Gtk2/speech.cc	Sun Feb 13 20:15:46 2005
@@ -46,7 +46,7 @@
 
   voices = GNOME_Speech_SynthesisDriver_getAllVoices (rv, &ev);
 
-  if (voices==NULL || BONOBO_EX (&ev)) {
+  if (voices==NULL || BONOBO_EX (&ev) || voices->_length==0) {
     printf(_("Unable to initialize voices"));
     speaker=NULL;
     return;
@@ -78,7 +78,8 @@
 void teardown_speech() {
 
   bonobo_object_release_unref (speaker, NULL);
-  CORBA_free (voices);
+  if (voices != NULL && voices->_length != 0)
+    CORBA_free (voices);
   CORBA_exception_free (&ev);
 
 }
