Oops, forgot to include patch-event.c:

--- event.c.orig	Tue Jul  3 00:46:38 2001
+++ event.c	Tue Jul  3 00:47:24 2001
@@ -11,6 +11,7 @@
 #endif
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <stdlib.h>
 #include <ctype.h>

--
Pete Fritchman <petef@databits.net>
Databits Network Services, Inc. <http://databits.net>
finger petef@databits.net for PGP key
