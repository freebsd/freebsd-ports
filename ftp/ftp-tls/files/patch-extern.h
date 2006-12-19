--- extern.h.orig	Thu Nov 21 07:52:55 2002
+++ extern.h	Mon Dec 18 23:23:03 2006
@@ -65,7 +65,11 @@
  *	@(#)extern.h	8.3 (Berkeley) 10/9/94
  */
 
+#ifndef __EXTERN_H
+#define __EXTERN_H
+
 #include <sys/types.h>
+#include "ftp_var.h"
 
 void    abort_remote __P((FILE *));
 void    abortpt __P((int));
@@ -217,3 +221,5 @@
 extern char	reply_string[];
 extern off_t	restart_point;
 extern int	NCMDS;
+
+#endif
