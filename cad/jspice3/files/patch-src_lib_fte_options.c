--- src/lib/fte/options.c.orig	2009-01-11 20:27:11.000000000 +0000
+++ src/lib/fte/options.c
@@ -66,7 +66,7 @@ def_fn(_iv_cpdebug)
 
 def_fn(_iv_history)
 {
-    if (!flag) return;
+    if (!flag) return (US_OK);
     if (v->va_type == VT_NUM)
         cp_maxhistlength = v->va_num;
     else if (v->va_type == VT_REAL)
@@ -930,27 +930,27 @@ struct variable **v1, **v2;
         v =  va_copy(plot_cur->pl_env);
     else
         v = NULL;
-    if (tv = cp_enqvar(kw_plots)) {
+    if ((tv = cp_enqvar(kw_plots))) {
         tv->va_next = v;
         v = tv;
     }
-    if (tv = cp_enqvar(kw_curplot)) {
+    if ((tv = cp_enqvar(kw_curplot))) {
         tv->va_next = v;
         v = tv;
     }
-    if (tv = cp_enqvar(kw_curplottitle)) {
+    if ((tv = cp_enqvar(kw_curplottitle))) {
         tv->va_next = v;
         v = tv;
     }
-    if (tv = cp_enqvar(kw_curplotname)) {
+    if ((tv = cp_enqvar(kw_curplotname))) {
         tv->va_next = v;
         v = tv;
     }
-    if (tv = cp_enqvar(kw_curplotdate)) {
+    if ((tv = cp_enqvar(kw_curplotdate))) {
         tv->va_next = v;
         v = tv;
     }
-    if (tv = cp_enqvar(kw_display)) {
+    if ((tv = cp_enqvar(kw_display))) {
         tv->va_next = v;
         v = tv;
     }
