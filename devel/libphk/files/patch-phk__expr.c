--- phk_expr.c.orig	2008-04-29 18:50:56 UTC
+++ phk_expr.c
@@ -52,8 +52,8 @@ dbg(struct e *e, const char *w)
 {
 	if (1)
 		return;
-	fprintf(stderr, "<%*.*s|", e->p - e->b, e->p - e->b, e->b);
-	fprintf(stderr, "%*.*s> %s\n", e->e - e->p, e->e - e->p, e->p, w);
+	fprintf(stderr, "<%*.*s|", (int)(e->p - e->b), (int)(e->p - e->b), e->b);
+	fprintf(stderr, "%*.*s> %s\n", (int)(e->e - e->p), (int)(e->e - e->p), e->p, w);
 }
 
 /*
@@ -289,7 +289,7 @@ phk_expr(const char *p, char **errs)
 	if (e->err != NULL) {
 		if (errs != NULL)
 			asprintf(errs, "Expression error:\n%s\n%*.*s^ %s\n",
-			    e->b, e->p - e->b, e->p - e->b, "", e->err);
+			    e->b, (int)(e->p - e->b), (int)(e->p - e->b), "", e->err);
 		return (NAN);
 	}
 	return (v);
