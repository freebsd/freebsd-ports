--- src/backend/utils/init/findbe.c.orig	Tue Feb 19 16:03:38 2002
+++ src/backend/utils/init/findbe.c	Tue Feb 19 16:03:45 2002
@@ -13,9 +13,9 @@
  */
 #include "postgres.h"
 
+#include <sys/types.h>
 #include <grp.h>
 #include <pwd.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 
