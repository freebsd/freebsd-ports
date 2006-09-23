--- http/servlet/http_servlet_cookieauth.c.orig	Sat Jan 22 06:01:58 2005
+++ http/servlet/http_servlet_cookieauth.c	Sun Sep 17 19:53:55 2006
@@ -54,6 +54,7 @@
 #include <pthread.h>
 
 #include <openssl/ssl.h>
+#include <openssl/md5.h>
 
 #include "structs/structs.h"
 #include "structs/type/array.h"
