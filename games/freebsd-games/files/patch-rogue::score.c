$FreeBSD$

--- rogue/score.c	30 Nov 1999 03:49:27 -0000	1.4
+++ rogue/score.c	21 Aug 2003 20:03:30 -0000
@@ -58,7 +58,6 @@
 #include "rogue.h"
 #include "pathnames.h"
 
-extern char login_name[];
 extern char *m_names[];
 extern short max_level;
 extern boolean score_only, no_skull, msg_cleared;
