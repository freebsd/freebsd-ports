--- tpexpr.cxx.old	Sat Feb 12 17:24:29 2000
+++ tpexpr.cxx	Sat Feb 12 17:24:41 2000
@@ -170,7 +170,7 @@
     if (!e->is_parameter() && (base == 0 || base == 1)) {
 	t->prepend(dprintf("items(%.*s", n, "****************"));
 	t->copy(e->f_tkn, e->l_tkn);
-	t->prepend(base == 0 ? ")-1" : ")");
+	t->prepend(base == 0 ? (char *) ")-1" : (char *) ")");
     } else { 
 	if (high == NULL) { 
 	    assert(high_expr != NULL);
