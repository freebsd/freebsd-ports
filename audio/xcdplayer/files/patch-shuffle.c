
$FreeBSD$

--- shuffle.c.orig	Tue Jan 12 19:59:38 1993
+++ shuffle.c	Mon Aug 25 00:38:35 2003
@@ -18,6 +18,9 @@
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
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
@@ -97,7 +102,7 @@
 		random_tracks[i] = try;
 	}
 
-	if (debug == True) {
+	if (app_data.debug == True) {
 		debug_printf(1, "shuffle_setup: ");
 		for (i = 0; i < cdi.ntracks; i++)
 			debug_printf(1, "%d ", random_tracks[i]);
