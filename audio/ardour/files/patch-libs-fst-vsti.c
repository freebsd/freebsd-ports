--- libs/fst/vsti.c.orig	Sat Mar 24 16:56:58 2007
+++ libs/fst/vsti.c	Sat Mar 24 16:59:07 2007
@@ -32,6 +32,8 @@
 #include <jackvst.h>
 #include <vst/aeffectx.h>
 
+#ifdef WITH_ALSA
+
 snd_seq_t *
 create_sequencer (const char* client_name, bool isinput)
 {
@@ -177,5 +179,5 @@
 	snd_seq_close (jvst->seq);
 }
 
-
+#endif
 
