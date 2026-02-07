--- main.c.orig	1996-11-07 16:01:43 UTC
+++ main.c
@@ -33,7 +33,7 @@ static char *_main_c_ident_ = "@(#)main.
 bool_t			exit_flag;	/* Flag indicating end of application */
 appdata_t		app_data;	/* Options data */
 widgets_t		widgets;	/* Holder of all widgets */
-FILE			*errfp = stderr;/* Error message stream */
+FILE			*errfp;		/* Error message stream */
 
 
 /***********************
@@ -95,7 +95,7 @@ usage(int argc, char **argv)
  * main
  *	The main function
  */
-void
+int
 main(int argc, char **argv)
 {
 	XtAppContext	app;
@@ -103,6 +103,7 @@ main(int argc, char **argv)
 
 	/* Initialize variables */
 	exit_flag = FALSE;
+	errfp = stderr;
 
 	/* Handle some signals */
 	signal(SIGINT, onsig);
