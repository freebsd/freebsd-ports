--- util.c.orig	2009-03-24 07:59:19.000000000 +0100
+++ util.c	2010-06-08 20:18:08.000000000 +0200
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
-#include <atomicio.h>
+#include "atomicio.h"
 #include <errno.h>
 #include <fcntl.h>
 #include <md5.h>
