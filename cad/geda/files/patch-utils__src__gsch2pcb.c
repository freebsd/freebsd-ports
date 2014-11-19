--- utils/src/gsch2pcb.c.orig	2013-08-18 08:44:47.000000000 +0200
+++ utils/src/gsch2pcb.c	2014-11-18 18:53:20.303642614 +0100
@@ -1397,13 +1397,13 @@
   pcbdata_path = g_getenv ("PCBDATA");  /* do not free return value */
   if (pcbdata_path != NULL) {
     /* If PCBDATA is set, use the value */
-    m4_pcbdir = g_strconcat (pcbdata_path, "/pcb/m4", NULL);
+    m4_pcbdir = g_strconcat (pcbdata_path, "/m4", NULL);
   } else {
     /* Use the default value passed in from the configure script
      * instead of trying to hard code a value which is very
      * likely wrong
      */
-    m4_pcbdir = g_strconcat (PCBDATADIR, "/pcb/m4", NULL);
+    m4_pcbdir = g_strconcat (PCBDATADIR, "/m4", NULL);
   }
 
   default_m4_pcbdir = g_strdup (m4_pcbdir);
