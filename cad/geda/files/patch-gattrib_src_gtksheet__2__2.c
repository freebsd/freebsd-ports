--- gattrib/src/gtksheet_2_2.c.orig	2013-09-25 20:59:27 UTC
+++ gattrib/src/gtksheet_2_2.c
@@ -57,6 +57,16 @@
 #include "../include/prototype.h"  /* function prototypes */
 #include "../include/globals.h"
 
+TOPLEVEL *pr_current;
+SHEET_DATA *sheet_head;
+
+GtkWidget *window;
+GtkWidget *notebook;
+GtkSheet **sheets;
+GtkWidget **scrolled_windows;
+GtkWidget *entry;
+GtkWidget *label;
+
 #ifdef HAVE_LIBDMALLOC
 #include <dmalloc.h>
 #endif
