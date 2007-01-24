--- sel_fld.c.orig	Sun Jan 21 21:09:19 2007
+++ sel_fld.c	Sun Jan 21 21:10:03 2007
@@ -1,6 +1,9 @@
 #include <stdio.h>
 #include "screen.h"
 
+static move_cur(char dirchar, int flag, int *rp, int *cp);
+static int nearestfld(int r, int c, int flag);
+
 /* define BANG if and only if your system supports the system() function.
  */
 #define	BANG
