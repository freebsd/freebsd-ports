--- client/cl_scrn.c.orig	Sun Dec 31 14:01:34 2006
+++ client/cl_scrn.c	Thu Mar 22 10:20:16 2007
@@ -34,6 +34,10 @@
 
 #include "client.h"
 
+#ifdef __unix__
+#include <sys/utsname.h>
+#endif
+
 float		scr_con_current;	// aproaches scr_conlines at scr_conspeed
 float		scr_conlines;		// 0.0 to 1.0 lines of console to display
 qboolean	scr_initialized;	// ready to draw
@@ -471,7 +475,6 @@
 	player_state_t *player_speed;
 	vec3_t		hvel;
 #if defined (__unix__)
-#include <sys/utsname.h>
 	struct utsname	info;
 	uname (&info);
 #endif
