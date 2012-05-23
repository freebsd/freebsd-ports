--- VAX/vax_sysdev.c.orig	2012-05-05 22:40:08.000000000 +0900
+++ VAX/vax_sysdev.c	2012-05-05 22:43:28.000000000 +0900
@@ -1556,8 +1556,14 @@
     if (sim_log)
         fprintf (sim_log, "Loading boot code from ka655x.bin\n");
     r = load_cmd (0, "-R ka655x.bin");
-    if (r != SCPE_OK)
-        return r;
+    if (r != SCPE_OK) {
+        printf ("Loading boot code from %%DATADIR%%/ka655x.bin\n");
+        if (sim_log)
+            fprintf (sim_log, "Loading boot code from %%DATADIR%%/ka655x.bin\n");
+        r = load_cmd (0, "-R %%DATADIR%%/ka655x.bin");
+        if (r != SCPE_OK)
+            return r;
+        }
     }
 sysd_powerup ();
 return SCPE_OK;
