--- tclxcircuit.c.orig	2017-04-25 12:36:04 UTC
+++ tclxcircuit.c
@@ -8947,7 +8947,7 @@ int defaultscript()
          sprintf(_STR2, "%s/tcl/%s", SCRIPTS_DIR, STARTUP_FILE);
          if ((fd = fopen(_STR2, "r")) == NULL) {
             Wprintf("Failed to open startup script \"%s\"\n", STARTUP_FILE);
-            return;
+            return TCL_ERROR;
 	 }
       }
    }
