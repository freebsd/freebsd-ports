--- src/interfaces/js.h.orig	Sun May  4 16:25:37 2003
+++ src/interfaces/js.h	Sun May  4 16:25:40 2003
@@ -65,7 +65,11 @@
 #  include <unistd.h>
 #  include <fcntl.h>
 
-#  if defined(__FreeBSD__) || defined(__NetBSD__)
+#  if defined(__FreeBSD__)
+#    include <sys/joystick.h>
+#    define JS_DATA_TYPE joystick
+#    define JS_RETURN (sizeof(struct JS_DATA_TYPE))
+#  elif defined(__NetBSD__)
 #    include <machine/joystick.h>
 #    define JS_DATA_TYPE joystick
 #    define JS_RETURN (sizeof(struct JS_DATA_TYPE))
