--- ./extra/fiddle~/fiddle~.c.orig	Mon Apr 15 15:52:45 2002
+++ ./extra/fiddle~/fiddle~.c	Sun Oct 20 02:48:51 2002
@@ -40,9 +40,7 @@
 #define fexp exp
 #define fsqrt sqrt
 #pragma warning (disable: 4305 4244)
-#endif
-
-#if (defined(__linux__) || defined(MACOSX))
+#else
 #define flog log
 #define fexp exp
 #define fsqrt sqrt
@@ -702,11 +700,11 @@
 
     for (npitch = 0; npitch < x->x_npitch; npitch++)
     {
-	int index;
+	int myindex;
 	float best;
 	if (npitch)
 	{
-	    for (best = 0, index = -1, j=1; j < maxbin-1; j++)
+	    for (best = 0, myindex = -1, j=1; j < maxbin-1; j++)
 	    {
 		if (histogram[j] > best && histogram[j] > histogram[j-1] &&
 		    histogram[j] > histogram[j+1])
@@ -726,7 +724,7 @@
 			if (histogram[j + sigfiddle_intpartialonset[k]]
 			    > histogram[j]) goto peaknogood;
 		    }
-		    index = j;
+		    myindex = j;
 		    best = histogram[j];
 		}
 	    peaknogood: ;
@@ -734,13 +732,13 @@
 	}
 	else
 	{
-	    for (best = 0, index = -1, j=0; j < maxbin; j++)
+	    for (best = 0, myindex = -1, j=0; j < maxbin; j++)
 		if (histogram[j] > best)
-		    index = j,  best = histogram[j];
+		    myindex = j,  best = histogram[j];
 	}
-	if (index < 0) break;
+	if (myindex < 0) break;
 	histvec[npitch].h_value = best;
-	histvec[npitch].h_index = index;
+	histvec[npitch].h_index = myindex;
     }
 #if 1
     if (x->x_nprint)
@@ -1641,8 +1639,7 @@
 {
      if (sp[0]->s_n > x->x_hop) {
     	x->x_downsample = sp[0]->s_n / x->x_hop;
-    	post("* warning: fiddle~: will downsample input by
-%ld",x->x_downsample);
+    	post("* warning: fiddle~: will downsample input by %ld",x->x_downsample);
     	x->x_sr = sp[0]->s_sr / x->x_downsample;
     } else {
     	x->x_downsample = 1;
