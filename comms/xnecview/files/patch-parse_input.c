--- parse_input.c.orig	Mon Jun  5 08:56:55 2006
+++ parse_input.c	Mon Jun  5 08:57:56 2006
@@ -527,6 +527,7 @@
 int read_nec_SC(char *s)     /* SC -> continuation of SM, SP, or SC */
 {
    Surface *su;
+   Surface *suLast;
    int ns;
    Point p3;
    int n;
@@ -575,7 +576,7 @@
       case 'C':
          n=sscanf(s,"SC%*i%d%g%g%g%g%g%g",&ns,&su->p2.x,&su->p2.y,&su->p2.z,&su->p3.x,&su->p3.y,&su->p3.z);
          if (n!=7 && n!=4) return Err_scan;
-         Surface *suLast=surfaces+(numsurfaces-2);
+         suLast=surfaces+(numsurfaces-2);
          su->p0=suLast->p3;
          su->p1=suLast->p2;
          updateextremes(&su->p2);
