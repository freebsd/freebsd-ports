--- Help.h.orig	Mon Sep 17 16:52:09 2001
+++ Help.h	Mon Sep 17 16:52:53 2001
@@ -11,6 +11,10 @@
 #ifndef __AUDACITY_HELP__
 #define __AUDACITY_HELP__
 
+#ifndef AUDACITY_HELP_DIR
+#define AUDACITY_HELP_DIR /usr/X11R6/share/audacity
+#endif
+
 void InitHelp(wxWindow * parent);
 void ShowHelp(wxWindow * parent);
 void ShowHelp(wxWindow * parent, wxString topic);
