--- registryd/deviceeventcontroller.c.orig	Wed Nov 27 16:36:12 2002
+++ registryd/deviceeventcontroller.c	Wed Nov 27 16:38:21 2002
@@ -32,6 +32,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <sys/time.h>
 #include <bonobo/bonobo-exception.h>
 
 #include <X11/Xlib.h>
