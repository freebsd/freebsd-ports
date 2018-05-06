--- widget/coollocal.h.orig	2018-04-24 22:04:24 UTC
+++ widget/coollocal.h
@@ -51,7 +51,6 @@ CWidget *allocate_widget (Window newwin,
 int eh_picture (struct cool_widget *w, XEvent * xevent, CEvent * cwevent);
 void drawstring_xy (Window win, int x, int y, const char *text);
 void drawstring_xy_hotkey (Window win, int x, int y, const char *text, int hotkey);
-int run_callbacks (CWidget * w, XEvent * xevent, CEvent * cwevent);
 void process_external_focus (Window win, int type);
 void focus_window (Window win);
 void link_scrollbar_to_textbox (CWidget * w, CWidget * textbox, XEvent * xevent, CEvent * cwevent, int whichscrbutton);
