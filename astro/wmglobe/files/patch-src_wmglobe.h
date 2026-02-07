--- src/wmglobe.h.orig	2001-08-12 15:41:22 UTC
+++ src/wmglobe.h
@@ -34,7 +34,6 @@
 #include <ctype.h>		/*toupper */
 #include <stdarg.h>
 #include <time.h>
-#include <sys/timeb.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <X11/Xlib.h>
@@ -83,17 +82,17 @@ typedef struct {
     int right;
 } MOUSE_REGION;
 
-MOUSE_REGION mouse_region[MAX_MOUSE_REGION];
+extern MOUSE_REGION mouse_region[MAX_MOUSE_REGION];
 
 typedef struct MPO {
     int r, g, b;
 } MPO;
 
-MPO *md[4], *mn[4];
+extern MPO *md[4], *mn[4];
 
-double solu[DIAMETRE][DIAMETRE][3];
-int tabsolu[DIAMETRE][DIAMETRE];
-int solution;
+extern double solu[DIAMETRE][DIAMETRE][3];
+extern int tabsolu[DIAMETRE][DIAMETRE];
+extern int solution;
 
 typedef struct {
     Pixmap pixmap;
@@ -102,72 +101,72 @@ typedef struct {
 } XpmIcon;
 
 
-Display *dpy;
+extern Display *dpy;
 
-char *dayfile, *nightfile, *dpy_name;
+extern char *dayfile, *nightfile, *dpy_name;
 
-Pixmap pix, pixmask;
+extern Pixmap pix, pixmask;
 
-XEvent Event;
+extern XEvent Event;
 
-RImage *map, *small, *mapnight;
+extern RImage *map, *small, *mapnight;
 
-XpmIcon screenpos, scrdate, scrdiv, numpix, txtpix, wmg;
+extern XpmIcon screenpos, scrdate, scrdiv, numpix, txtpix, wmg;
 
-Window iconwin, win;
-int onlyshape, option_iw;
-GC NormalGC;
+extern Window iconwin, win;
+extern int onlyshape, option_iw;
+extern GC NormalGC;
 
 /********* rendering********/
 
 #if WITH_MARKERS
-double marker[MAX_MARKERS][3];
-int nb_marker, sun_marker, moon_marker;
-RColor sun_col, moon_col;
-double moon_lat,moon_long;
+extern double marker[MAX_MARKERS][3];
+extern int nb_marker, sun_marker, moon_marker;
+extern RColor sun_col, moon_col;
+extern double moon_lat,moon_long;
 #endif
 
-double delay, time_multi;
+extern double delay, time_multi;
 /*
  * struct timeval delta_tim, last_tim, next_tim, render_tim, base_tim,
  *  vec_tim;
  * 
  * time_t beg_time, ini_time,t1901;
  */
-struct timeval tlast, tnext, trend, tdelay, tini, tbase;
-time_t tsunpos;
+extern struct timeval tlast, tnext, trend, tdelay, tini, tbase;
+extern time_t tsunpos;
 
-int sens, fun, funx, funy, oknimap, mratiox, mratioy, gotoscr;
+extern int sens, fun, funx, funy, oknimap, mratiox, mratioy, gotoscr;
 
-int typecadre, p_type, use_nightmap, use_default_nightmap, use_nmap_ini, 
-firstTime, stoprand, do_something, iop;
+extern int typecadre, p_type, use_nightmap, use_default_nightmap,
+       use_nmap_ini, firstTime, stoprand, do_something, iop;
 
-double v_lat, v_long, old_dvlat, old_dvlong, dv_lat, dv_long;
-double dlat, dlong, addlat, addlong, ratiox, ratioy, dawn;
+extern double v_lat, v_long, old_dvlat, old_dvlong, dv_lat, dv_long;
+extern double dlat, dlong, addlat, addlong, ratiox, ratioy, dawn;
 
-double sun_lat;
-double sun_long;
+extern double sun_lat;
+extern double sun_long;
 
-double fov;
-double radius;
-double proj_dist;		/* distance to projection plane */
+extern double fov;
+extern double radius;
+extern double proj_dist;		/* distance to projection plane */
 
-double center_dist;		/*  distance to center of earth */
+extern double center_dist;		/*  distance to center of earth */
 
-double ambient_light;		/* how dark is the dark side? */
+extern double ambient_light;		/* how dark is the dark side? */
 
-double light_x, light_y, light_z;	/* vector of sunlight with lengt 1 */
+extern double light_x, light_y, light_z;	/* vector of sunlight with lengt 1 */
 
-double c_coef, b_coef;
-double zoom;
-int radius_proj, aml;		/* radius of sphere on screen */
+extern double c_coef, b_coef;
+extern double zoom;
+extern int radius_proj, aml;		/* radius of sphere on screen */
 
-RColor noir;
+extern RColor noir;
 #ifdef DEBUG
-double minhz;
+extern double minhz;
 #endif
 
-int stable;
+extern int stable;
 
 /****************************************************************/
 /* Function Prototypes                                          */
