--- VAX/vax_sysdev.c.orig	Sat Mar 24 09:13:42 2007
+++ VAX/vax_sysdev.c	Sat Mar 24 09:17:45 2007
@@ -1524,8 +1524,15 @@
     if (sim_log) fprintf (sim_log, 
         "Loading boot code from ka655x.bin\n");
     r = load_cmd (0, "-R ka655x.bin");
-    if (r != SCPE_OK) return r;
+    if (r != SCPE_OK) {
+        printf ("Loading boot code from %%PREFIX%%/share/simh/ka655x.bin\n");
+        if (sim_log) fprintf (sim_log, 
+            "Loading boot code from %%PREFIX%%/share/simh/ka655x.bin\n");
+        r = load_cmd (0, "-R %%PREFIX%%/share/simh/ka655x.bin");
+        if (r != SCPE_OK)
+    	    return r;
     }
+}
 return SCPE_OK;
 }
 
