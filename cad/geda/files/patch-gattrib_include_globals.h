--- gattrib/include/globals.h.orig	2013-08-18 17:02:48 UTC
+++ gattrib/include/globals.h
@@ -76,7 +76,7 @@
  * structs.h
  */
 /*------------------------------------------------------------------*/
-TOPLEVEL *pr_current;
+extern TOPLEVEL *pr_current;
 
 /*------------------------------------------------------------------*/
 /*!
@@ -85,7 +85,7 @@ TOPLEVEL *pr_current;
  * callbacks.  It is defined in structs.h
  */
 /*------------------------------------------------------------------*/
-SHEET_DATA *sheet_head;
+extern SHEET_DATA *sheet_head;
 
 /*------------------------------------------------------------------
  * GTKsheet includes: stuff for dealing with windows.
@@ -94,18 +94,14 @@ SHEET_DATA *sheet_head;
 #define DEFAULT_SPACE 8
 #define NUM_SHEETS 3            /* Components, Nets, and Pins */
 
-GtkWidget *window;              /* Main window */
-GtkWidget *notebook;
+extern GtkWidget *window;       /* Main window */
+extern GtkWidget *notebook;
 
-GtkSheet **sheets;             /* These are the spreadsheet widgets themselves */
+extern GtkSheet **sheets;      /* These are the spreadsheet widgets themselves */
 
-GtkWidget **scrolled_windows;
-GtkWidget *entry;
-GtkWidget *location;
-GtkWidget *left_button;
-GtkWidget *center_button;
-GtkWidget *right_button;
-GtkWidget *label;
+extern GtkWidget **scrolled_windows;
+extern GtkWidget *entry;
+extern GtkWidget *label;
 
 /* command line switch settings */
 extern int verbose_mode;
