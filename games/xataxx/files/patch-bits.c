--- bits.c.orig
+++ bits.c
@@ -1,7 +1,10 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <math.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/time.h>
 #include "struct.h"
@@ -16,7 +19,7 @@
 #define NFDSHIFT 5				/* Shift based on above */
 #ifndef howmany
 #define	howmany(x, y)	(((x)+((y)-1))/(y))
-#endif howmany
+#endif
 
 #define	NBBY	8		/* number of bits in a byte */
 
