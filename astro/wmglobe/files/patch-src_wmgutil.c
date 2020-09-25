--- src/wmgutil.c.orig	2020-09-15 14:29:30 UTC
+++ src/wmgutil.c
@@ -32,6 +32,37 @@
 #include "scrtime.xpm"
 #include "scrdiv.xpm"
 
+/*
+ * variables globales
+ */
+
+MOUSE_REGION mouse_region[MAX_MOUSE_REGION];
+MPO *md[4], *mn[4];
+int solution;
+char *dayfile, *nightfile, *dpy_name;
+XpmIcon screenpos, scrdate, scrdiv, numpix, txtpix, wmg;
+int onlyshape, option_iw;
+int nb_marker, sun_marker, moon_marker;
+RColor sun_col, moon_col;
+double delay, time_multi;
+int sens, fun, funx, funy, oknimap, mratiox, mratioy, gotoscr;
+int typecadre, p_type, use_nightmap, use_default_nightmap, use_nmap_ini,
+    firstTime, stoprand, do_something, iop;
+double v_lat, v_long, old_dvlat, old_dvlong, dv_lat, dv_long;
+double dlat, dlong, addlat, addlong, ratiox, ratioy, dawn;
+double sun_lat;
+double sun_long;
+double fov;
+double radius;
+double proj_dist;		/* distance to projection plane */
+double ambient_light;
+double zoom;
+RColor noir;
+double minhz;
+int stable;
+
+
+
 static void move_earth(double vla, double vlo);
 static int flush_expose(Window w);
 static void mqparam();
