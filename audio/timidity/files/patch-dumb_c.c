--- dumb_c.c.orig	Mon May 20 16:01:17 1996
+++ dumb_c.c	Tue Dec  4 23:45:01 2001
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
