--- src/sequencer.so.c.orig	Mon Feb 17 04:20:44 2003
+++ src/sequencer.so.c	Fri Apr 25 02:44:42 2003
@@ -136,6 +136,8 @@
 void runSequencer(LADSPA_Handle instance,
                   unsigned long sample_count)
 {
+    int i, rst;
+    unsigned long s;
     Sequencer *plugin = (Sequencer *)instance;
 
     /* Gate */
@@ -167,9 +169,7 @@
 
     unsigned int step_index = plugin->step_index;
     unsigned int loop_index = lrintf(loop_steps);
-    int rst = lrintf(reset);
-    int i;
-    unsigned long s;
+    rst = lrintf(reset);
 
     loop_index = loop_index == 0 ?  1 : loop_index;
     loop_index = loop_index > SEQUENCER_MAX_INPUTS ? SEQUENCER_MAX_INPUTS : loop_index;
@@ -223,12 +223,12 @@
     void (*run_functions[])(LADSPA_Handle,
                             unsigned long) = {runSequencer};
 
-    sequencer_descriptors = (LADSPA_Descriptor **)calloc(SEQUENCER_VARIANT_COUNT, sizeof(LADSPA_Descriptor));
-
     char label[12];
     char name[33];
     char loop_point_label[20];
     char value_label[14];
+
+    sequencer_descriptors = (LADSPA_Descriptor **)calloc(SEQUENCER_VARIANT_COUNT, sizeof(LADSPA_Descriptor));
 
 /* Mmmm. Lovely... */
     sprintf(label, "%s%d", "sequencer", SEQUENCER_MAX_INPUTS);
