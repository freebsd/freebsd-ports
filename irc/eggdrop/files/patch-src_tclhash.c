--- src/tclhash.c.orig  2011-10-06 09:19:05.000000000 -0800
+++ src/tclhash.c       2011-10-06 09:25:14.000000000 -0800
@@ -1264,7 +1264,7 @@
   for (i = 0; cc[i].name; i++) {
     egg_snprintf(p, sizeof p, "*%s:%s", tl->name,
                  cc[i].funcname ? cc[i].funcname : cc[i].name);
-    l = nmalloc(Tcl_ScanElement(p, &k));
+    l = nmalloc(Tcl_ScanElement(p, &k) + 1);
     Tcl_ConvertElement(p, l, k | TCL_DONT_USE_BRACES);
     table[0].cdata = (void *) cc[i].func;
     add_cd_tcl_cmds(table);
@@ -1282,7 +1282,7 @@
   for (i = 0; cc[i].name; i++) {
     egg_snprintf(p, sizeof p, "*%s:%s", table->name,
                  cc[i].funcname ? cc[i].funcname : cc[i].name);
-    l = nmalloc(Tcl_ScanElement(p, &k));
+    l = nmalloc(Tcl_ScanElement(p, &k) + 1);
     Tcl_ConvertElement(p, l, k | TCL_DONT_USE_BRACES);
     Tcl_DeleteCommand(interp, p);
     unbind_bind_entry(table, cc[i].flags, cc[i].name, l);

