$FreeBSD$
--- lib/psy.c.orig	Mon Feb 26 05:37:59 2001
+++ lib/psy.c	Wed Mar 21 15:50:10 2001
@@ -191,7 +191,7 @@
   p->total_octave_lines=maxoc-p->firstoc+1;
 
   p->ath=_ogg_malloc(n*sizeof(float));
-  p->octave=_ogg_malloc(n*sizeof(int));
+  p->octave=_ogg_malloc(n*sizeof(long));
   p->bark=_ogg_malloc(n*sizeof(float));
   p->vi=vi;
   p->n=n;
