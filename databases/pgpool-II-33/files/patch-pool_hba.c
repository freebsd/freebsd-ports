--- ./pool_hba.c.orig	2014-03-24 14:30:01.000000000 +0000
+++ ./pool_hba.c	2014-06-29 14:58:09.893352941 +0100
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <errno.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #include "pool.h"
 #include "pool_path.h"
