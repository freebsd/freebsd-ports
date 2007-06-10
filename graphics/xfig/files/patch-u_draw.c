--- u_draw.c.orig	Tue Jul 26 09:40:00 2005
+++ u_draw.c
@@ -282,7 +282,7 @@
 
     /* setup clipping so that spline doesn't protrude beyond arrowhead */
     /* also create the arrowheads */
-    clip_arrows(a,O_ARC,op,0);
+    clip_arrows((F_line *)a,O_ARC,op,0);
 
     /* draw the arc itself */
     draw_point_array(canvas_win, op, a->depth, a->thickness,
@@ -296,10 +296,10 @@
     /* draw the arrowheads, if any */
     if (a->type != T_PIE_WEDGE_ARC) {
       if (a->for_arrow) {
-	    draw_arrow(a, a->for_arrow, farpts, nfpts, farfillpts, nffillpts, op);
+	    draw_arrow((F_line *)a, a->for_arrow, farpts, nfpts, farfillpts, nffillpts, op);
       }
       if (a->back_arrow) {
-	    draw_arrow(a, a->back_arrow, barpts, nbpts, barfillpts, nbfillpts, op);
+	    draw_arrow((F_line *)a, a->back_arrow, barpts, nbpts, barfillpts, nbfillpts, op);
       }
     }
     /* write the depth on the object */
@@ -2067,7 +2067,7 @@
     if (success) {
 	/* setup clipping so that spline doesn't protrude beyond arrowhead */
 	/* also create the arrowheads */
-	clip_arrows(spline,O_SPLINE,op,4);
+	clip_arrows((F_line *)spline,O_SPLINE,op,4);
 
 	draw_point_array(canvas_win, op, spline->depth, spline->thickness,
 		       spline->style, spline->style_val,
@@ -2078,9 +2078,9 @@
 	set_clip_window(clip_xmin, clip_ymin, clip_xmax, clip_ymax);
 
 	if (spline->for_arrow)	/* forward arrow  */
-	    draw_arrow(spline, spline->for_arrow, farpts, nfpts, farfillpts, nffillpts, op);
+	    draw_arrow((F_line *)spline, spline->for_arrow, farpts, nfpts, farfillpts, nffillpts, op);
 	if (spline->back_arrow)	/* backward arrow  */
-	    draw_arrow(spline, spline->back_arrow, barpts, nbpts, barfillpts, nbfillpts, op);
+	    draw_arrow((F_line *)spline, spline->back_arrow, barpts, nbpts, barfillpts, nbfillpts, op);
 	/* write the depth on the object */
 	debug_depth(spline->depth,spline->points->x,spline->points->y);
     }
