--- util/rsa_util.c.orig	Sat Jan 22 06:02:19 2005
+++ util/rsa_util.c	Sun Sep 17 19:58:23 2006
@@ -50,6 +50,7 @@
 
 #include <openssl/ssl.h>
 #include <openssl/err.h>
+#include <openssl/md5.h>
 
 #include "structs/structs.h"
 #include "structs/type/array.h"
