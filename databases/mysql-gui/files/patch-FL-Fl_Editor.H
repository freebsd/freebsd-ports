--- FL/Fl_Editor.H.orig	Sat Aug 18 18:19:48 2001
+++ FL/Fl_Editor.H	Sat Aug 18 17:32:18 2001
@@ -186,6 +186,7 @@
 	Fl_Color textcolor() const { return(Fl_Color)textcolor_; }
 	void textcolor(uchar n) { textcolor_ = n; }
 	void LoadFrom(FILE *file) { engine->LoadFrom(file); ShowCursor(CURSOR_UNHIDE); SyncDisplay(); }
+	void LoadSQL (const char *query) { engine->LoadSQL(query); ShowCursor(CURSOR_UNHIDE); SyncDisplay(); }
 	void SaveTo(FILE *file) { engine->SaveTo(file); }
 	void LoadFrom(const char *buffer) { engine->LoadFrom(buffer); ShowCursor(CURSOR_UNHIDE); SyncDisplay(); }
 	void SaveTo(char *buffer) { engine->SaveTo(buffer); }
