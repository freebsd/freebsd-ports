--- jdk/src/solaris/native/sun/awt/wsutils.h
+++ jdk/src/solaris/native/sun/awt/wsutils.h
@@ -70,7 +70,7 @@ from The Open Group.
  *
  ******************************************************************************/
 
-typedef unsigned long Pixel;
+#include <X11/Intrinsic.h> /* For Pixel */
 
 /* This is the actual structure returned by the X server describing the
  * SERVER_OVERLAY_VISUAL property.
