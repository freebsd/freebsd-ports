--- src/pilot.c.orig	2022-07-02 17:04:58 UTC
+++ src/pilot.c
@@ -43,6 +43,8 @@
 #define PILOT_STD_RADIUS 4.1 /* Normal radius for pilot */
 #define PILOT_PAR_RADIUS 8.0 /* Parachuting radius for pilot */
 
+struct Pilot Pilot = {};
+
 /* List of active pilots */
 struct dllist *pilot_list;
 
