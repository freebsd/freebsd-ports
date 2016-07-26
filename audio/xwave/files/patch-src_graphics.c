--- src/graphics.c.orig	1998-11-08 23:22:55 UTC
+++ src/graphics.c
@@ -30,7 +30,7 @@
 
 #ifdef linux
 #include <endian.h>
-#elif defined (FreeBSD)
+#elif defined (__FreeBSD__)
 #include <machine/endian.h>
 #elif defined (sgi)
 #include <sys/endian.h>
@@ -1476,7 +1476,7 @@ void expose_action (Widget w, Main_Data 
     if (md->mb->exposing) return;
     */
     
-#if defined (linux) || defined (FreeBSD)
+#if defined (linux) || defined (__FreeBSD__)
     if (resizing) {
 	resizing=FALSE;
 	return;
@@ -1532,7 +1532,7 @@ Next_Wave *get_nw(Main_Data *md,Widget w
 
 void expose_canvas (Widget w, Main_Data *md, XExposeEvent *event, Boolean *flg)
 {
-#if defined (linux) || defined (FreeBSD)
+#if defined (linux) || defined (__FreeBSD__)
     if (resizing) {
 	if (!event->count) resizing=FALSE;
 	return;
