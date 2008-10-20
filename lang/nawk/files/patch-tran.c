diff -u -p -r1.6 -r1.9.10.1
--- tran.c.orig	2005/07/03 15:18:11	1.6
+++ tran.c	2007/11/06 23:07:52	1.9.10.1
@@ -210,7 +210,10 @@ Cell *setsymtab(const char *n, const cha
 	int h;
 	Cell *p;
 
-	if (n != NULL && (p = lookup(n, tp)) != NULL) {
+	if (n == NULL)
+		n = "";
+
+	if ((p = lookup(n, tp)) != NULL) {
 		   dprintf( ("setsymtab found %p: n=%s s=\"%s\" f=%g t=%o\n",
 			p, NN(p->nval), NN(p->sval), p->fval, p->tval) );
 		return(p);
@@ -282,6 +285,7 @@ Awkfloat setfval(Cell *vp, Awkfloat f)	/
 {
 	int fldno;
 
+	f += 0.0;		/* normalise negative zero to positive zero */
 	if ((vp->tval & (NUM | STR)) == 0) 
 		funnyvar(vp, "assign to");
 	if (isfld(vp)) {
