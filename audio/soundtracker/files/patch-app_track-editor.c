--- app/track-editor.c.orig	2006-02-25 12:30:54 UTC
+++ app/track-editor.c
@@ -603,6 +603,8 @@ track_editor_handle_keys (int shift,
 		    }
 		    
                     if(!GUI_ENABLED && !ASYNCEDIT) { // Recording mode 
+                            XMNote *note;
+
                         if(pressed){ // Insert note
 			    
                             for(c = 0; c < 32; c++){ // Cleanup
@@ -624,7 +626,7 @@ track_editor_handle_keys (int shift,
                             reckey[c].chn = t->cursor_ch;
                             reckey[c].act = TRUE;
                             
-                            XMNote *note = &t->curpattern->channels[t->cursor_ch][t->patpos];
+                            note = &t->curpattern->channels[t->cursor_ch][t->patpos];
                             note->note = i;
                             note->instrument = gui_get_current_instrument();
                             tracker_redraw_current_row(t);
@@ -645,7 +647,7 @@ track_editor_handle_keys (int shift,
                            if (!insert_noteoff)
                                goto fin_note;
                            
-                           XMNote *note = &t->curpattern->channels[reckey[c].chn][t->patpos];
+                           note = &t->curpattern->channels[reckey[c].chn][t->patpos];
                            note->note = 97;
                            note->instrument = 0;
                            tracker_redraw_current_row(t);
