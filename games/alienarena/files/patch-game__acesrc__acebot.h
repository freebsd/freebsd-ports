--- ./game/acesrc/acebot.h.orig	Fri Jun  1 14:05:51 2007
+++ ./game/acesrc/acebot.h	Sat Jul 21 09:32:13 2007
@@ -60,6 +60,13 @@
 #ifndef _ACEBOT_H
 #define _ACEBOT_H
 
+// Directory for reading files in "botinfo", writing is always done in "."
+#ifdef DATADIR
+#define BOTDIR	DATADIR
+#else
+#define BOTDIR	"."
+#endif
+
 // Only 100 allowed for now (probably never be enough edicts for 'em
 #define MAX_BOTS 100
 
