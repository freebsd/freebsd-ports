--- spice3f5/common/src/lib/fte/device.c.orig	1994-03-08 05:14:19.000000000 +0000
+++ spice3f5/common/src/lib/fte/device.c
@@ -594,7 +594,7 @@ com_alter_common(wl, do_model)
 
     if (!ft_curckt) {
         fprintf(cp_err, "Error: no circuit loaded\n");
-        return;
+        return (0);
     }
 
     words = wl;
@@ -608,7 +608,7 @@ com_alter_common(wl, do_model)
     }
     if (!words) {
 	fprintf(cp_err, "Error: no assignment found.\n");
-	return;
+	return (0);
     }
 
     /* device parameter = expr
@@ -643,29 +643,29 @@ com_alter_common(wl, do_model)
     }
     if (!dev) {
 	fprintf(cp_err, "Error: no model or device name provided.\n" );
-	return;
+	return (0);
     }
 
     words = eqword->wl_next;
     names = ft_getpnames(words, false);
     if (!names) {
 	fprintf(cp_err, "Error: cannot parse new parameter value.\n");
-	return;
+	return (0);
     }
     dv = ft_evaluate(names);
     free_pnode(names);
     if (!dv)
-	return;
+	return (0);
     if (dv->v_length < 1) {
 	fprintf(cp_err, "Error: cannot evaluate new parameter value.\n");
-	return;
+	return (0);
     }
 
     if_setparam(ft_curckt->ci_ckt, &dev, param, dv, do_model);
 
     /* Vector data (dv) should get garbage-collected. */
 
-    return;
+    return (0);
 
 #ifdef notdef
     while (wl) {
