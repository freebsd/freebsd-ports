--- uip/msh.c.orig	2001-06-14 16:41:30 UTC
+++ uip/msh.c
@@ -17,14 +17,7 @@ static char ident[] = "@(#)$Id: msh.c,v 
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#ifndef	SYS5
-#include <sgtty.h>
-#else	/* SYS5 */
-#include <termio.h>
-#ifndef	NOIOCTLH
 #include <sys/ioctl.h>
-#endif	/* NOIOCTLH */
-#endif	/* SYS5 */
 #include <pwd.h>
 #include <setjmp.h>
 #include <signal.h>
