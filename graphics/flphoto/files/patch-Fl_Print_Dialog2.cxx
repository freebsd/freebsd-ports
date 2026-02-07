--- Fl_Print_Dialog2.cxx.orig	2006-11-26 21:45:08 UTC
+++ Fl_Print_Dialog2.cxx
@@ -56,6 +56,7 @@
 
 #ifdef HAVE_LIBCUPS
 #  include <cups/cups.h>
+#  include <cups/ppd.h>
 #endif // HAVE_LIBCUPS
 
 
