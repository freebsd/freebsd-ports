--- phk_expr.c~	2008-04-29 18:50:56.000000000 +0000
+++ phk_expr.c	2008-09-08 09:17:19.205920000 +0000
@@ -52,8 +52,8 @@
 {
 	if (1)
 		return;
-	fprintf(stderr, "<%*.*s|", e->p - e->b, e->p - e->b, e->b);
-	fprintf(stderr, "%*.*s> %s\n", e->e - e->p, e->e - e->p, e->p, w);
+	fprintf(stderr, "<%*.*s|", (int)(e->p - e->b), (int)(e->p - e->b), e->b);
+	fprintf(stderr, "%*.*s> %s\n", (int)(e->e - e->p), (int)(e->e - e->p), e->p, w);
 }
 
 /*
@@ -289,7 +289,7 @@
 	if (e->err != NULL) {
 		if (errs != NULL)
 			asprintf(errs, "Expression error:\n%s\n%*.*s^ %s\n",
-			    e->b, e->p - e->b, e->p - e->b, "", e->err);
+			    e->b, (int)(e->p - e->b), (int)(e->p - e->b), "", e->err);
 		return (NAN);
 	}
 	return (v);
