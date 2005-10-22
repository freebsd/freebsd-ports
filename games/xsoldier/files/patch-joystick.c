
$FreeBSD$

--- joystick.c.orig
+++ joystick.c
@@ -8,6 +8,8 @@
 
 #include <config.h>
 
+#ifdef JSTK
+
 /* read */
 #include <unistd.h>
 /* exit */
@@ -95,3 +97,5 @@
 	if (js.y >  150) joymask |= Down; /* Was 1000 */
     }
 }
+
+#endif	/* JSTK */
