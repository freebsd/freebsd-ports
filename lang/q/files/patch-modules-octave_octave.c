--- modules/octave/octave.c.orig	2007-11-14 03:04:18.000000000 +0100
+++ modules/octave/octave.c	2007-11-14 03:06:27.000000000 +0100
@@ -126,6 +126,8 @@
 static const char *octaverc = ".octaverc";
 static const char *octaverc_bak = ".octaverc.$$$";
 
+static int send_octave(char *);
+
 /* handle SIGINT and SIGTERM */
 
 #if RETSIGTYPE == void
@@ -272,7 +274,6 @@
   FILE *fp, *fp2;
   char buf[bufsz];
   int bak = 0;
-  static int send_octave(char *cmd);
   static int init = 0;
   if (!octp) {
     /* get the command from the OCTAVE variable if defined */
