--- libsoxconvert/src/libsoxconvert.c.orig	2009-06-03 22:35:58.000000000 +0200
+++ libsoxconvert/src/libsoxconvert.c	2009-09-20 21:38:42.000000000 +0200
@@ -83,7 +83,7 @@
   assert(sox_add_effect(chain, e, &in->signal, &in->signal) == SOX_SUCCESS);
 
   /* Flow samples through the effects processing chain until EOF is reached */
-  sox_flow_effects(chain, NULL);
+  sox_flow_effects(chain, NULL, NULL);
 
   foutput("%s\n", "[INF]  Exiting SoX...");
   /* All done; tidy up: */
