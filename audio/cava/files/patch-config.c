Remove noncurses output method which only produces a garbled mess
on terminals.

--- config.c.orig	2020-05-29 23:28:58 UTC
+++ config.c
@@ -173,10 +173,6 @@ bool validate_config(struct config_params *p, struct e
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
 #ifdef NCURSES
         write_errorf(error,
                      "output method %s is not supported, supported methods are: 'ncurses', "
-                     "'noncurses' and 'raw'\n",
+                     "and 'raw'\n",
                      outputMethod);
         return false;
 #endif
@@ -408,7 +404,7 @@ bool load_config(char configPath[PATH_MAX], struct con
     }
 
 #ifdef NCURSES
-    outputMethod = (char *)iniparser_getstring(ini, "output:method", "noncurses");
+    outputMethod = (char *)iniparser_getstring(ini, "output:method", "ncurses");
 #endif
 #ifndef NCURSES
     outputMethod = (char *)iniparser_getstring(ini, "output:method", "noncurses");
