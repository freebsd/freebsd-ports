--- VAX/vax_sysdev.c.orig	2008-11-23 11:57:54.000000000 +0100
+++ VAX/vax_sysdev.c	2009-02-12 06:24:49.000000000 +0100
@@ -1553,9 +1553,15 @@
     if (sim_log)
         fprintf (sim_log, "Loading boot code from ka655x.bin\n");
     r = load_cmd (0, "-R ka655x.bin");
-    if (r != SCPE_OK)
-        return r;
+    if (r != SCPE_OK) {
+        printf ("Loading boot code from /usr/local/share/simh/ka655x.bin\n");
+        if (sim_log)
+	    fprintf (sim_log, "Loading boot code from /usr/local/share/simh/ka655x.bin\n");
+        r = load_cmd (0, "-R /usr/local/share/simh/ka655x.bin");
+        if (r != SCPE_OK)
+            return r;
     }
+}
 return SCPE_OK;
 }
 
