--- src/arch/unix/joy.c.orig	Tue Feb 20 10:11:02 2007
+++ src/arch/unix/joy.c	Tue Feb 20 10:11:13 2007
@@ -117,7 +117,7 @@
 #endif
 
 #elif defined(BSD_JOYSTICK)
-#include <machine/joystick.h>
+#include <sys/joystick.h>
 #define JS_DATA_TYPE joystick
 #define JS_RETURN    sizeof(struct joystick)
 int     use_old_api=1;
