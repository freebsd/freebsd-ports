--- hanzim.c.orig	Wed Mar 20 01:34:31 2002
+++ hanzim.c	Sat Jun 14 09:20:04 2003
@@ -204,6 +204,16 @@
 main(int argc, char *argv[]) {
   Tcl_Interp *interp;
 
+/* hanzim need a running XFree to do its initial setup, rectify */
+  if (!(strcmp(argv[1], "-port-install")))
+  {
+        char *portdatadir = "%%PREFIX%%/lib/hanzim";
+        init_vars(portdatadir);
+        kanzi(portdatadir);
+        kanhe(portdatadir);
+        exit(0);
+  }
+                                                                               
   /* do an initial parse of the command-line options so that help message */
   /* can be printed and we can set some global flags */
   interp = Tcl_CreateInterp();
@@ -460,10 +470,14 @@
   struct _timeb tp;
   _ftime(&tp);
 #else
+/*
   struct timeb	tp;
   ftime(&tp);
+*/
+  time_t	t;
+  time(&t);
 #endif
-  srand(tp.millitm);
+  srand(t);
 
   if (!quiet) {
     printf("\n\nWelcome to Hanzi Master, where YOU will master the hanzi.\n");
