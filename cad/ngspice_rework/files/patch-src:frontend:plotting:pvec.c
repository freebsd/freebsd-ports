--- src/frontend/plotting/pvec.c.orig	Fri Sep 17 17:30:10 2004
+++ src/frontend/plotting/pvec.c	Fri Sep 17 17:30:33 2004
@@ -47,8 +47,6 @@
     case GRID_SMITHGRID:
         strcat(buf, ", grid = smithgrid (not xformed)");
         break;
-
-    default:
     }
 
     switch (d->v_plottype) {
@@ -60,8 +58,6 @@
     case PLOT_POINT:
         strcat(buf, ", plot = point");
         break;
-
-    default:
     }
     if (d->v_defcolor) {
         sprintf(buf2, ", color = %s", d->v_defcolor);
