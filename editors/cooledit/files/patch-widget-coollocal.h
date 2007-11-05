--- widget/coollocal.h.orig	2007-11-02 00:37:50.000000000 +0100
+++ widget/coollocal.h	2007-11-02 00:45:22.000000000 +0100
@@ -49,7 +49,6 @@
 int eh_picture (struct cool_widget *w, XEvent * xevent, CEvent * cwevent);
 void drawstring_xy (Window win, int x, int y, const char *text);
 void drawstring_xy_hotkey (Window win, int x, int y, const char *text, int hotkey);
-int run_callbacks (CWidget * w, XEvent * xevent, CEvent * cwevent);
 void process_external_focus (Window win, int type);
 void focus_window (Window win);
 void link_scrollbar_to_textbox (CWidget * w, CWidget * textbox, XEvent * xevent, CEvent * cwevent, int whichscrbutton);
