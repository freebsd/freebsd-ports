--- utils.c.orig	Wed Oct 30 00:48:16 1991
+++ utils.c	Sat Jun 16 02:10:19 2007
@@ -4,6 +4,7 @@
 #include <stdio.h>
 #include <math.h>
 #include <ctype.h>
+#include <string.h>
 #include "defs.h"
 /* some include files vary in location */
 #ifdef VAXC
@@ -300,9 +301,8 @@
      struct info_struct *out_info;
      struct one_opt *opt;	/* put command line options here */
 #define may_override(name) if (opt[(int) name].set) switch (opt[(int) name].tag) {	    \
-											    case integer: out_info->name = opt[(int) name].val.i; break;			    \
-											    case real: out_info->name = opt[(int) name].val.r; break;			    \
-											    case lst: case str: strcpy(out_info->name, opt[(int) name].val.str); break;}
+					    case integer: out_info->name = opt[(int) name].val.i; break; \
+					    case real: out_info->name = opt[(int) name].val.r; break; }
 {
   /* and now overide the device if the command line wants us to */
   may_override(pxl_in);
