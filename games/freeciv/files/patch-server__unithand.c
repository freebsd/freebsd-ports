--- ./server/unithand.c.orig	Tue Dec 27 00:37:53 2005
+++ ./server/unithand.c	Tue Sep 26 11:21:55 2006
@@ -1593,7 +1593,8 @@
   struct unit *punit = player_find_unit_by_id(pplayer, packet->unit_id);
   int i;
 
-  if (!punit || packet->length < 0 || punit->activity != ACTIVITY_IDLE) {
+  if (!punit || packet->length < 0 || punit->activity != ACTIVITY_IDLE
+      || packet->length > MAX_LEN_ROUTE) {
     return;
   }
 
