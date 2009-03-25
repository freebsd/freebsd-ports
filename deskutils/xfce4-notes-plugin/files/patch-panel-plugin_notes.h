--- panel-plugin/notes.h.orgi	2009-03-25 14:08:06.000000000 +0100
+++ panel-plugin/notes.h	2009-03-25 14:08:43.000000000 +0100
@@ -155,7 +155,7 @@
 
 gboolean                notes_window_hide               (NotesWindow *notes_window);
 
-inline void             notes_window_sort_names         (NotesWindow *notes_window);
+/*inline void             notes_window_sort_names         (NotesWindow *notes_window); */
 
 gint                    notes_window_strcasecmp         (NotesWindow *notes_window0,
                                                          NotesWindow *notes_window1);
