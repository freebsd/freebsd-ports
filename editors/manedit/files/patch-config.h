
$FreeBSD$

--- config.h.orig	Mon Feb 19 12:58:51 2001
+++ config.h	Mon Feb 19 19:56:21 2001
@@ -22,7 +22,7 @@
 /*
  *	ManEdit global directory:
  */
-#define MEDIT_GLOBAL_DIR	"/usr/share/manedit"
+#define MEDIT_GLOBAL_DIR	PREFIX"/share/manedit"
 
 /*
  *	Manual page help sub directory (MEDIT_GLOBAL_DIR will
@@ -101,7 +101,7 @@
  *	%f = filename
  *	%p = optional parameters
  */
-#define MEDIT_CMD_MANPAGE_TO_OUTPUT	"/usr/bin/man %p %f"
+#define MEDIT_CMD_MANPAGE_TO_OUTPUT	PREFIX"/bin/manwrap %p %f"
 
 
 
