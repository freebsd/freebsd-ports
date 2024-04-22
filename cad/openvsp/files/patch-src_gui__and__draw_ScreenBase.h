--- src/gui_and_draw/ScreenBase.h.orig	2024-03-26 08:35:31 UTC
+++ src/gui_and_draw/ScreenBase.h
@@ -11,6 +11,7 @@
 #if !defined(SCREENBASE__INCLUDED_)
 #define SCREENBASE__INCLUDED_
 
+#undef nitems
 #include <FL/Fl.H>
 #include <FL/Fl_Browser.H>
 #include <FL/Fl_Check_Browser.H>
