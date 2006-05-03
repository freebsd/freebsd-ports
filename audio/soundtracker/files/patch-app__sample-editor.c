--- app/sample-editor.c.orig	Sat Feb 25 21:26:05 2006
+++ app/sample-editor.c	Sun Feb 26 13:05:51 2006
@@ -2647,13 +2647,15 @@
 static void 
 sample_editor_crop()
 {
-    int start = sampledisplay->sel_start, end = sampledisplay->sel_end;
+    int start, end, l;
+
+    start = sampledisplay->sel_start, end = sampledisplay->sel_end;
 
     if(current_sample == NULL || start == -1) 
     return;
-
-    int l = current_sample->sample.length;
     
+    l = current_sample->sample.length;
+
     sample_editor_lock_sample();
     sample_editor_delete(current_sample, 0, start);
     sample_editor_delete(current_sample, end - start, l - start);
