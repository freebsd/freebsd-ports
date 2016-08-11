
$NetBSD: pkgsrc/audio/xcdplayer/patches/patch-al,v 1.4 2005/12/11 20:48:46 joerg Exp $

--- shuffle.c.orig	1993-01-12 18:59:38 UTC
+++ shuffle.c
@@ -18,6 +18,9 @@
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -29,6 +32,8 @@
 
 static unsigned char	*random_tracks;
 
+extern AppData app_data;
+
 void
 shuffle_setup() {
 	extern char	*malloc();
@@ -97,7 +102,7 @@ shuffle_setup() {
 		random_tracks[i] = try;
 	}
 
-	if (debug == True) {
+	if (app_data.debug == True) {
 		debug_printf(1, "shuffle_setup: ");
 		for (i = 0; i < cdi.ntracks; i++)
 			debug_printf(1, "%d ", random_tracks[i]);
