--- status.cc.orig	Wed Apr 11 21:12:24 2001
+++ status.cc	Mon Feb  3 04:10:54 2003
@@ -1,4 +1,5 @@
 #include "status.h"
+#undef Success
 #include <sqlplus.hh>
 extern char *pass; extern int w8_x, w8_y;
 #include <FL/Fl_Pixmap.H>
