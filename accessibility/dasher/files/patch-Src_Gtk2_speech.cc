--- Src/Gtk2/speech.cc.orig	Fri Sep 17 06:53:53 2004
+++ Src/Gtk2/speech.cc	Sat Feb 26 01:00:12 2005
@@ -78,7 +78,8 @@
 void teardown_speech() {
 
   bonobo_object_release_unref (speaker, NULL);
-  CORBA_free (voices);
+  if (voices != NULL && !BONOBO_EX (&ev) && voices->_length != 0)
+    CORBA_free (voices);
   CORBA_exception_free (&ev);
 
 }
