--- bse/bseloader.h.orig	2008-02-26 23:42:45.000000000 +0100
+++ bse/bseloader.h	2008-02-26 23:42:55.000000000 +0100
@@ -56,7 +56,7 @@
   gchar         **xinfos;
   /* loader-specific */
   union {
-    guint         uint;
+    guint         u_int;
     gpointer      ptr;
     gfloat        vfloat;
   }               loader_data[8];
