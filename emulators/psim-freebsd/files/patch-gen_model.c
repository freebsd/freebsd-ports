--- sim/ppc/gen-model.c	2003/10/20 23:38:14	1.1
+++ sim/ppc/gen-model.c	2003/10/20 23:38:53
@@ -377,7 +377,7 @@
     lf_printf(file, "    }\n");
     lf_printf(file, "  }\n");
     lf_printf(file, "\n");
-    lf_printf(file, "  error(\"Unknown model '%%s', Models which are known are:%%s\n\",\n");
+    lf_printf(file, "  error(\"Unknown model '%%s', Models which are known are:%%s\\n\",\n");
     lf_printf(file, "        name,\n");
     lf_printf(file, "        \"");
     for(model_ptr = models; model_ptr; model_ptr = model_ptr->next) {
