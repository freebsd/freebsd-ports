--- fileio.c.orig	2023-10-22 13:42:02 UTC
+++ fileio.c
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/param.h>
 
 #include "def.h"
 #include "kbd.h"
@@ -705,7 +706,7 @@ expandtilde(const char *fn)
 	struct passwd	*pw;
 	struct stat	 statbuf;
 	const char	*cp;
-	char		 user[LOGIN_NAME_MAX], path[NFILEN];
+	char		 user[MAXLOGNAME], path[NFILEN];
 	char		*ret;
 	size_t		 ulen, plen;
 
