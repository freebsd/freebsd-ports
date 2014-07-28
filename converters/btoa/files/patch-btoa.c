--- btoa.c.orig	Fri Oct  8 13:00:00 1993
+++ btoa.c	Wed May  8 14:54:17 2002
@@ -20,7 +20,7 @@
 FILE *outfile;
 
 
-void main(argc, argv)
+int main(argc, argv)
 int argc;
 BYTE **argv;
 {
@@ -39,6 +39,11 @@
   error = openinput = openoutput = a_to_b = diagnosis = repair = FALSE;
   new_version = TRUE;
   infilename = NULL;
+
+  /* Assume a_to_b = TRUE if we're called 'atob' */
+  if (!strncmp(argv[0] + strlen(argv[0]) - 4, "atob", 4)) {
+    a_to_b = TRUE;
+  }
 
   /* Scan for '-' options. The rest must be file names. */
   while (!error && argc > 1 && *argv[1] == '-')
