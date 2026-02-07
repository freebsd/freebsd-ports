--- GUI/Widgets/Fl_Trigger.h.orig	2001-04-20 00:48:10.000000000 +0400
+++ GUI/Widgets/Fl_Trigger.h	2014-02-13 05:50:41.290374838 +0400
@@ -24,6 +24,9 @@
 #ifndef TRIGGERWIDGET
 #define TRIGGERWIDGET
 
+using std::istream;
+using std::ostream;
+
 class Fl_Trigger : public Fl_Widget
 {
 public:
