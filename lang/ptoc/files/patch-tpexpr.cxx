--- tpexpr.cxx.orig	2001-04-04 15:56:02 UTC
+++ tpexpr.cxx
@@ -170,7 +170,7 @@ void array_tp::insert_dimensions(expr_node* e, array_t
     if (!e->is_parameter() && (base == 0 || base == 1)) {
 	t->prepend(dprintf("items(%.*s", n, "****************"));
 	t->copy(e->f_tkn, e->l_tkn);
-	t->prepend(base == 0 ? ")-1" : ")");
+	t->prepend(base == 0 ? (char *) ")-1" : (char *) ")");
     } else { 
 	if (high == NULL) { 
 	    assert(high_expr != NULL);
