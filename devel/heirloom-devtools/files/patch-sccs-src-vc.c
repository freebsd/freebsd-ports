--- sccs/src/vc.c.orig	2023-01-13 17:08:38 UTC
+++ sccs/src/vc.c
@@ -36,6 +36,9 @@
  * Sccsid @(#)vc.c	1.4 (gritter) 3/25/07
  */
 /*	from OpenSolaris "sccs:cmd/vc.c"	*/
+#if defined(__FreeBSD__)
+# include <limits.h>	/* MB_LEN_MAX */
+#endif /* __FreeBSD__ */
 # include	<defines.h>
 # include	<locale.h>
 
