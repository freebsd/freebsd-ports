--- VAX/vax_sysdev.c.orig	2016-12-01 22:43:43 UTC
+++ VAX/vax_sysdev.c
@@ -1556,8 +1556,14 @@ if (*rom == 0) {                        
     if (sim_log)
         fprintf (sim_log, "Loading boot code from ka655x.bin\n");
     r = load_cmd (0, "-R ka655x.bin");
-    if (r != SCPE_OK)
-        return r;
+    if (r != SCPE_OK) {
+        printf ("Loading boot code from /usr/local/share/simh/ka655x.bin\n");
+        if (sim_log)
+            fprintf (sim_log, "Loading boot code from /usr/local/share/simh/ka655x.bin\n");
+        r = load_cmd (0, "-R /usr/local/share/simh/ka655x.bin");
+        if (r != SCPE_OK)
+            return r;
+        }
     }
 sysd_powerup ();
 return SCPE_OK;
