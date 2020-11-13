Remove noncurses output method which only produces a garbled mess
on terminals.

--- config.c.orig	2020-10-29 12:33:01 UTC
+++ config.c
@@ -181,10 +181,6 @@ bool validate_config(struct config_params *p, struct e
         return false;
 #endif
     }
-    if (strcmp(outputMethod, "noncurses") == 0) {
-        p->om = OUTPUT_NONCURSES;
-        p->bgcol = 0;
-    }
     if (strcmp(outputMethod, "raw") == 0) { // raw:
         p->om = OUTPUT_RAW;
         p->bar_spacing = 0;
@@ -220,7 +216,7 @@ bool validate_config(struct config_params *p, struct e
 #ifndef NCURSES
         write_errorf(
             error,
-            "output method %s is not supported, supported methods are: 'noncurses' and 'raw'\n",
+            "output method %s is not supported, supported methods are: 'raw'\n",
             outputMethod);
         return false;
 #endif
@@ -228,7 +224,7 @@ bool validate_config(struct config_params *p, struct e
 #ifdef NCURSES
         write_errorf(error,
                      "output method %s is not supported, supported methods are: 'ncurses', "
-                     "'noncurses' and 'raw'\n",
+                     "and 'raw'\n",
                      outputMethod);
         return false;
 #endif
