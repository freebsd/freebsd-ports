--- ./Fl_Print_Dialog2.cxx.orig	2006-11-26 22:45:08.000000000 +0100
+++ ./Fl_Print_Dialog2.cxx	2012-12-22 12:41:39.000000000 +0100
@@ -56,6 +56,7 @@
 
 #ifdef HAVE_LIBCUPS
 #  include <cups/cups.h>
+#  include <cups/ppd.h>
 #endif // HAVE_LIBCUPS
 
 
