diff -u -r1.1.1.1 layer2.c
--- layer2.c	1999/02/10 12:13:06	1.1.1.1
+++ layer2.c	2004/09/02 21:43:58
@@ -265,6 +265,11 @@
   fr->jsbound = (fr-&gt;>mode == MPG_MD_JOINT_STEREO) ?
      (fr->mode_ext<<2)+4 : fr->II_sblimit;
 
+  if (fr->jsbound > fr->II_sblimit) {
+	  fprintf(stderr, "Truncating stereo boundary to sideband limit.\n");
+	  fr->jsbound=fr->II_sblimit;
+  }
+  
   if(stereo == 1 || single == 3)
     single = 0;
