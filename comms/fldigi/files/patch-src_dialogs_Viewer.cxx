--- src/dialogs/Viewer.cxx.orig	2008-08-14 13:31:08.000000000 -0400
+++ src/dialogs/Viewer.cxx	2008-08-17 20:28:40.000000000 -0400
@@ -91,7 +91,7 @@
 
 #if HAVE_REGEX_H
 regex_t* seek_re = 0;
-void re_comp(const char* needle)
+void fl_re_comp(const char* needle)
 {
         if (seek_re)
                 regfree(seek_re);
@@ -306,7 +306,7 @@
 #else
 	static Fl_Color seek_color[2] = { FL_FOREGROUND_COLOR,
 					  adjust_color(FL_RED, FL_BACKGROUND2_COLOR) }; // invalid RE
-	re_comp(inpSeek->value());
+	fl_re_comp(inpSeek->value());
 	if (inpSeek->textcolor() != seek_color[!seek_re]) {
 		inpSeek->textcolor(seek_color[!seek_re]);
 		inpSeek->redraw();
