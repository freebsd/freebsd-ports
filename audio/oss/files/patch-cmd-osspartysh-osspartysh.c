--- cmd/osspartysh/osspartysh.c.orig	2009-11-13 10:20:53.000000000 -0500
+++ cmd/osspartysh/osspartysh.c	2010-01-19 13:31:23.000000000 -0500
@@ -45,8 +45,8 @@
 #include <libutil.h>
 #else
 #include <pty.h>
-#endif
 #include <utmp.h>
+#endif
 #include <errno.h>
 
 #define PARTYSH_MAGIC		"ParTySH"
