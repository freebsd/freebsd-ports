--- fileio.c.orig	2026-05-19 14:58:49 UTC
+++ fileio.c
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/param.h>
 
 #include "def.h"
 #include "kbd.h"
@@ -703,7 +704,7 @@ expandtilde(const char *fn)
 	struct passwd	*pw;
 	struct stat	 statbuf;
 	const char	*cp;
-	char		 user[LOGIN_NAME_MAX], path[NFILEN];
+	char		 user[MAXLOGNAME], path[NFILEN];
 	char		*ret;
 	size_t		 ulen, plen;
 
