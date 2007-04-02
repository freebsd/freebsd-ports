--- ppp/ppp_auth_radius.c.orig	Sat Jan 22 06:02:04 2005
+++ ppp/ppp_auth_radius.c	Sun Sep 17 19:55:28 2006
@@ -44,6 +44,8 @@
 #include "ppp/ppp_auth.h"
 #include "ppp/ppp_msoft.h"
 
+#include <openssl/md5.h>
+
 #include <poll.h>
 #include <radlib.h>
 #include <radlib_vs.h>
--- ppp/ppp_auth_radius.c.orig	Sun Apr  1 23:13:10 2007
+++ ppp/ppp_auth_radius.c	Sun Apr  1 23:16:01 2007
@@ -462,7 +462,7 @@
 
 		/* Compensate for broken servers that leave out the ID byte */
 		if (len > 0 && (len < 3 || ((const char *)data)[1] != '=')) {
-			((const char *)data)++;
+			data = (const char *)data + 1;
 			len--;
 		}
 
