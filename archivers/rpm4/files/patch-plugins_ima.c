--- plugins/ima.c.orig	2018-06-21 09:08:06 UTC
+++ plugins/ima.c
@@ -1,8 +1,6 @@
 #include "system.h"
 
 #include <errno.h>
-#include <sys/xattr.h>
-
 #include <rpm/rpmfi.h>
 #include <rpm/rpmte.h>
 #include <rpm/rpmfiles.h>
