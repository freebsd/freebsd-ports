Index: ChangeLog
===================================================================
--- ChangeLog	(revision 153)
+++ ChangeLog	(revision 154)
@@ -1,5 +1,9 @@
 ChangeLog
 
+	(2007/05/22) PS1 - xfig backend: added depth to opaque components
+	to avoid them floating to the background. Suggested by Rafael
+	Laboissiere.
+
 v1.8 2007/04/09
 	(2007/04/08) PS1 - portability: use 'test' instead of '[' in shell
 	scripts.
Index: src/backend_xfig.c
===================================================================
--- src/backend_xfig.c	(revision 153)
+++ src/backend_xfig.c	(revision 154)
@@ -124,13 +124,13 @@
   return n;
 }
 
-/* do one path. First should be 1 on the very first path, else 0. */
-static int xfig_path(FILE *fout, potrace_curve_t *curve, trans_t t, int sign) {
+/* do one path. */
+static void xfig_path(FILE *fout, potrace_curve_t *curve, trans_t t, int sign, int depth) {
   int i;
   dpoint_t *c;
   int m = curve->n;
 
-  fprintf(fout, "3 1 0 0 0 %d 50 0 20 0.000 0 0 0 %d\n", sign=='+' ? 32 : 33, npoints(curve, m));
+  fprintf(fout, "3 1 0 0 0 %d %d 0 20 0.000 0 0 0 %d\n", sign=='+' ? 32 : 33, depth, npoints(curve, m));
 
   for (i=0; i<m; i++) {
     c = curve->c[i];
@@ -154,15 +154,43 @@
       break;
     }
   }
-  return 0;
 }
 
+/* render a whole tree */
+static void xfig_write_paths(FILE *fout, potrace_path_t *plist, trans_t t, int depth) {
+  potrace_path_t *p, *q;
+
+  for (p=plist; p; p=p->sibling) {
+    xfig_path(fout, &p->curve, t, p->sign, depth);
+    for (q=p->childlist; q; q=q->sibling) {
+      xfig_path(fout, &q->curve, t, q->sign, depth >= 1 ? depth-1 : 0);
+    }
+    for (q=p->childlist; q; q=q->sibling) {
+      xfig_write_paths(fout, q->childlist, t, depth >= 2 ? depth-2 : 0);
+    }
+  }
+}
+
+/* calculate the depth of a tree. Call with d=0. */
+static int xfig_get_depth(potrace_path_t *plist) {
+  potrace_path_t *p;
+  int max =0;
+  int d;
+
+  for (p=plist; p; p=p->sibling) {
+    d = xfig_get_depth(p->childlist);
+    if (d > max) {
+      max = d;
+    }
+  }
+  return max + 1;
+}
+
 /* ---------------------------------------------------------------------- */
 /* Backend. */
 
 /* public interface for XFIG */
 int page_xfig(FILE *fout, potrace_path_t *plist, imginfo_t *imginfo) {
-  potrace_path_t *p;
   trans_t t;
   double si, co;
   double origx = imginfo->trans.orig[0] + imginfo->lmar;
@@ -174,6 +202,7 @@
   pageformat_t *f;
   int i;
   int x0, y0, x1, y1;  /* in xfig's coordinates */
+  int depth;
   
   si = sin(info.angle/180*M_PI);
   co = cos(info.angle/180*M_PI);
@@ -220,11 +249,21 @@
   fprintf(fout, "0 33 #%06x\n", info.fillcolor);
   fprintf(fout, "6 %d %d %d %d\n", x0-75, y1-35, x1+75, y0+35); /* bounding box */
 
+  /* determine depth of the tree */
+  depth = xfig_get_depth(plist);
+
+  /* figure out appropriate xfig starting depth. Note: xfig only has 1000 depths available */
+  if (depth <= 40) {
+    depth = 50;
+  } else if (depth < 990) {
+    depth += 10;
+  } else {
+    depth = 999;
+  }
+
   /* write paths. Note: can never use "opticurve" with this backend -
      it just does not approximate Bezier curves closely enough.  */
-  list_forall (p, plist) {
-    xfig_path(fout, &p->curve, t, p->sign);
-  }
+  xfig_write_paths(fout, plist, t, depth);
 
   fprintf(fout, "-6\n"); /* end bounding box */
 
