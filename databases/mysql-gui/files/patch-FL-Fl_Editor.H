--- FL/Fl_Editor.H.orig	Mon Feb  3 01:53:09 2003
+++ FL/Fl_Editor.H	Mon Feb  3 02:04:37 2003
@@ -210,6 +210,7 @@
 	Fl_Color textcolor() const { return(Fl_Color)textcolor_; }
 	void textcolor(uchar n) { textcolor_ = n; }
 	void LoadFrom(FILE *file) { engine->LoadFrom(file); engine->Command(MOVE_BOF); SyncDisplay(); ShowCursor(CURSOR_UNHIDE); }
+	void LoadSQL (const char *query) { engine->LoadSQL(query); ShowCursor(CURSOR_UNHIDE); SyncDisplay(); }
 	void SaveTo(FILE *file) { engine->SaveTo(file); }
 	void LoadFrom(const char *buffer) { engine->LoadFrom(buffer); SyncDisplay(); ShowCursor(CURSOR_UNHIDE);  }
 	void SaveTo(char *buffer) { engine->SaveTo(buffer); }
