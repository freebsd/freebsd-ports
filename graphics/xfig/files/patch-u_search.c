--- u_search.c.orig	Tue Jul 26 09:40:00 2005
+++ u_search.c
@@ -33,10 +33,10 @@
 #define TOLERANCE ((int)((display_zoomscale < 20.0? 4: 14) * \
 			PIX_PER_INCH/DISPLAY_PIX_PER_INCH/display_zoomscale))
 
-static int	(*manipulate) ();
-static int 	(*handlerproc_left) ();
-static int	(*handlerproc_middle) ();
-static int	(*handlerproc_right) ();
+static void	(*manipulate) ();
+static void 	(*handlerproc_left) ();
+static void	(*handlerproc_middle) ();
+static void	(*handlerproc_right) ();
 static int	type;
 static long	objectcount;
 static long	n;
@@ -61,7 +61,7 @@
 void toggle_objecthighlight (void);
 
 Boolean
-next_arc_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_arc_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     int		    i;
 
@@ -141,7 +141,7 @@
 }
 
 Boolean
-next_ellipse_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_ellipse_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     double	    a, b, dx, dy;
     double	    dis, r, tol;
@@ -207,7 +207,7 @@
  */
 
 Boolean
-next_line_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_line_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     F_point	   *point;
     int		    x1, y1, x2, y2;
@@ -257,7 +257,7 @@
  */
 
 Boolean
-next_spline_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_spline_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     F_point	   *point;
     int		    x1, y1, x2, y2;
@@ -297,7 +297,7 @@
 }
 
 Boolean
-next_text_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_text_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     int		    dum;
 
@@ -326,7 +326,7 @@
 }
 
 Boolean
-next_compound_found(int x, int y, int tolerance, int *px, int *py, int shift)
+next_compound_found(int x, int y, int tolerance, int *px, int *py, unsigned int shift)
 {
     float	    tol2;
 
@@ -561,7 +561,7 @@
 }
 
 Boolean
-next_arc_point_found(int x, int y, int tol, int *point_num, int shift)
+next_arc_point_found(int x, int y, int tol, int *point_num, unsigned int shift)
        		                                 
 /* dirty trick - point_num is called as a `F_point *point_num' */
 {
@@ -592,7 +592,7 @@
 }
 
 Boolean
-next_ellipse_point_found(int x, int y, int tol, int *point_num, int shift)
+next_ellipse_point_found(int x, int y, int tol, int *point_num, unsigned int shift)
        		                                 
 /* dirty trick - point_num is called as a `F_point *point_num' */
 {
@@ -623,7 +623,7 @@
 }
 
 Boolean
-next_line_point_found(int x, int y, int tol, F_point **p, F_point **q, int shift)
+next_line_point_found(int x, int y, int tol, F_point **p, F_point **q, unsigned int shift)
 {
     F_point	   *a, *b;
 
@@ -655,7 +655,7 @@
 }
 
 Boolean
-next_spline_point_found(int x, int y, int tol, F_point **p, F_point **q, int shift)
+next_spline_point_found(int x, int y, int tol, F_point **p, F_point **q, unsigned int shift)
 {
     if (!anyspline_in_mask())
 	return False;
@@ -683,7 +683,7 @@
 }
 
 Boolean
-next_compound_point_found(int x, int y, int tol, int *p, int *q, int shift)
+next_compound_point_found(int x, int y, int tol, int *p, int *q, unsigned int shift)
        		                             
 /* dirty trick - p and q are called with type `F_point' */
 {
@@ -729,19 +729,19 @@
 }
 
 void
-init_searchproc_left(int (*handlerproc) (/* ??? */))
+init_searchproc_left(void (*handlerproc) (/* ??? */))
 {
     handlerproc_left = handlerproc;
 }
 
 void
-init_searchproc_middle(int (*handlerproc) (/* ??? */))
+init_searchproc_middle(void (*handlerproc) (/* ??? */))
 {
     handlerproc_middle = handlerproc;
 }
 
 void
-init_searchproc_right(int (*handlerproc) (/* ??? */))
+init_searchproc_right(void (*handlerproc) (/* ??? */))
 {
     handlerproc_right = handlerproc;
 }
@@ -761,7 +761,7 @@
 	switch (type) {
 	case O_ELLIPSE:
 	    /* dirty trick - px returns point_num */
-	    found = next_ellipse_point_found(x, y, TOLERANCE, &px, shift);
+	    found = next_ellipse_point_found(x, y, TOLERANCE, (int *)&px, shift);
 	    break;
 	case O_POLYLINE:
 	    found = next_line_point_found(x, y, TOLERANCE, &px, &py, shift);
@@ -771,10 +771,10 @@
 	    break;
 	case O_ARC:
 	    /* dirty trick - px returns point_num */
-	    found = next_arc_point_found(x, y, TOLERANCE, &px, shift);
+	    found = next_arc_point_found(x, y, TOLERANCE, (int *)&px, shift);
 	    break;
 	case O_COMPOUND:
-	    found = next_compound_point_found(x, y, TOLERANCE, &px, &py, shift);
+	    found = next_compound_point_found(x, y, TOLERANCE, (int *)&px, (int *)&py, shift);
 	    break;
 	}
 	if (found) {
