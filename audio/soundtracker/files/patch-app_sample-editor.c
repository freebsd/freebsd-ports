--- app/sample-editor.c.orig	2006-02-25 12:26:05 UTC
+++ app/sample-editor.c
@@ -2647,13 +2647,15 @@ sample_editor_trim(gboolean trbeg, gbool
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
