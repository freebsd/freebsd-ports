--- app/track-editor.c.orig	Sat Feb 25 21:30:54 2006
+++ app/track-editor.c	Sun Feb 26 13:08:32 2006
@@ -603,6 +603,8 @@
 		    }
 		    
                     if(!GUI_ENABLED && !ASYNCEDIT) { // Recording mode 
+                            XMNote *note;
+
                         if(pressed){ // Insert note
 			    
                             for(c = 0; c < 32; c++){ // Cleanup
@@ -624,7 +626,7 @@
                             reckey[c].chn = t->cursor_ch;
                             reckey[c].act = TRUE;
                             
-                            XMNote *note = &t->curpattern->channels[t->cursor_ch][t->patpos];
+                            note = &t->curpattern->channels[t->cursor_ch][t->patpos];
                             note->note = i;
                             note->instrument = gui_get_current_instrument();
                             tracker_redraw_current_row(t);
@@ -645,7 +647,7 @@
                            if (!insert_noteoff)
                                goto fin_note;
                            
-                           XMNote *note = &t->curpattern->channels[reckey[c].chn][t->patpos];
+                           note = &t->curpattern->channels[reckey[c].chn][t->patpos];
                            note->note = 97;
                            note->instrument = 0;
                            tracker_redraw_current_row(t);
