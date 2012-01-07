--- ./main.c.orig	1996-11-07 11:01:43.000000000 -0500
+++ ./main.c	2012-01-07 00:26:29.000000000 -0500
@@ -33,7 +33,7 @@
 bool_t			exit_flag;	/* Flag indicating end of application */
 appdata_t		app_data;	/* Options data */
 widgets_t		widgets;	/* Holder of all widgets */
-FILE			*errfp = stderr;/* Error message stream */
+FILE			*errfp;		/* Error message stream */
 
 
 /***********************
@@ -95,7 +95,7 @@
  * main
  *	The main function
  */
-void
+int
 main(int argc, char **argv)
 {
 	XtAppContext	app;
@@ -103,6 +103,7 @@
 
 	/* Initialize variables */
 	exit_flag = FALSE;
+	errfp = stderr;
 
 	/* Handle some signals */
 	signal(SIGINT, onsig);
