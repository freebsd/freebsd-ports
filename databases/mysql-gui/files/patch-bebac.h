--- bebac.h.orig	Wed Apr 11 21:12:19 2001
+++ bebac.h	Mon Feb  3 02:28:44 2003
@@ -5,6 +5,7 @@
 #include <FL/Fl.H>
 #include <FL/Fl_Double_Window.H>
 #include "client.h"
+#undef Success
 #include <mysql++>
 extern Connection *con;
 extern void do_exit(Fl_Double_Window*, void*);
