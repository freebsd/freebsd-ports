--- src/objects-x.c.orig	Tue May 16 16:40:38 2006
+++ src/objects-x.c	Tue May 16 16:44:08 2006
@@ -1215,6 +1215,7 @@
     stderr_out ("Failed fontconfig initialization\n");
   else
     {
+      struct charset_reporter *cr;
       FcPattern *fontxft;	/* long-lived, freed at end of this block */
       FcResult fcresult;
       FcConfig *fcc;
@@ -1302,7 +1303,6 @@
 	 Optimization:  cache the generated FcCharSet in the Mule charset.
          Don't forget to destroy it if the Mule charset gets deallocated. */
 
-      struct charset_reporter *cr;
       for (cr = charset_table;
 	   cr->charset && !EQ (*(cr->charset), charset);
 	   cr++)
