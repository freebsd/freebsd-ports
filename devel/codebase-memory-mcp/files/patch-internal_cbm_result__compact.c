--- internal/cbm/result_compact.c.orig	2026-10-16 06:23:44 UTC
+++ internal/cbm/result_compact.c
@@ -440,6 +440,15 @@ static void cr_walk(cr_ctx_t *c, CBMFileResult *r) {
         cr_str(c, &r->channels.items[i].transport);
         cr_str(c, &r->channels.items[i].enclosing_func_qn);
     }
+    cr_array(c, (void **)&r->sysctls.items, r->sysctls.count, sizeof(CBMSysctl));
+    for (int i = 0; i < r->sysctls.count && r->sysctls.items; i++) {
+        cr_str(c, &r->sysctls.items[i].leaf_name);
+        cr_str(c, &r->sysctls.items[i].parent_symbol);
+        cr_str(c, &r->sysctls.items[i].self_symbol);
+        cr_str(c, &r->sysctls.items[i].handler);
+        cr_str(c, &r->sysctls.items[i].enclosing_func_qn);
+        cr_str(c, &r->sysctls.items[i].file_rel);
+    }
     cr_array(c, (void **)&r->field_types.items, r->field_types.count, sizeof(CBMFieldType));
     for (int i = 0; i < r->field_types.count && r->field_types.items; i++) {
         cr_str(c, &r->field_types.items[i].class_qn);
@@ -611,6 +620,7 @@ void cbm_result_compact(CBMFileResult *result) {
     tmp.string_refs.cap = tmp.string_refs.count;
     tmp.infra_bindings.cap = tmp.infra_bindings.count;
     tmp.channels.cap = tmp.channels.count;
+    tmp.sysctls.cap = tmp.sysctls.count;
     tmp.diagram_arrows.cap = tmp.diagram_arrows.count;
     tmp.field_types.cap = tmp.field_types.count;
     tmp.doc_links.cap = tmp.doc_links.count;
