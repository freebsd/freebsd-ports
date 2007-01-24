--- listing.c.orig	Sat Mar 14 23:22:09 1992
+++ listing.c	Sun Jan 21 20:48:40 2007
@@ -6,21 +6,36 @@
  * format of the listing file is one line per screen update.
  */
 
+#include <string.h>
 #include <stdio.h>
 #include <math.h>
 #include "screen.h"
 
-extern char *strcpy();
+#if (defined(__unix__) || defined(unix)) && !defined(USG)             
+#include <sys/param.h>                                                
+#endif
+
+#if defined(VMS) || defined(unix)
+#include <errno.h>
+#endif
 
 #ifdef VMS
 #include <perror.h>
-#include <errno.h>
 #else
+#ifndef BSD
 extern char *sys_errlist[];
+#endif
 extern errno;
 #endif
 
 #define	errsys	(sys_errlist[errno])
+
+static lst_reset();
+static lst_select_fields();
+static lst_turn_off();
+static lst_turn_on();
+static lst_file();
+static display_listing_file(FILE *lfp);
 
 
 #define	TRACE(x)	{FILE *fp = fopen("trace","a"); fprintf x; fclose(fp);}
