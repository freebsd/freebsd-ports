--- sim/ppc/gen-model.c.orig	Fri Feb 20 17:15:51 2004
+++ sim/ppc/gen-model.c	Fri Feb 20 17:18:16 2004
@@ -377,7 +377,7 @@
     lf_printf(file, "    }\n");
     lf_printf(file, "  }\n");
     lf_printf(file, "\n");
-    lf_printf(file, "  error(\"Unknown model '%%s', Models which are known are:%%s\n\",\n");
+    lf_printf(file, "  error(\"Unknown model '%%s', Models which are known are:%%s\",\n");
     lf_printf(file, "        name,\n");
     lf_printf(file, "        \"");
     for(model_ptr = models; model_ptr; model_ptr = model_ptr->next) {
