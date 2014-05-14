--- ./dumb_c.c.orig	1996-05-20 09:01:17.000000000 -0500
+++ ./dumb_c.c	2013-04-21 10:18:23.000000000 -0500
@@ -66,10 +66,12 @@
   ctl_expression, ctl_panning, ctl_sustain, ctl_pitch_bend
 };
 
-static FILE *infp=stdin, *outfp=stdout; /* infp isn't actually used yet */
+static FILE *infp, *outfp; /* infp isn't actually used yet */
 
 static int ctl_open(int using_stdin, int using_stdout)
 {
+  infp = stdin;
+  outfp = stdout;
   if (using_stdin && using_stdout)
     infp=outfp=stderr;
   else if (using_stdout)
