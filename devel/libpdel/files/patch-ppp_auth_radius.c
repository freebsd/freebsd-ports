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
