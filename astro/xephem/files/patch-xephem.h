--- xephem.h.orig	2012-12-30 17:01:12 UTC
+++ xephem.h
@@ -12,12 +12,12 @@
 
 #include <stdarg.h>		/* be kind to those who don't use xe_msg() */
 
+#include "net.h"		/* has to be included before astro.h because of openssl */
 #include "astro.h"
 #include "ip.h"
 
 /* local glue files */
 #include "map.h"
-#include "net.h"
 #include "patchlevel.h"
 #include "preferences.h"
 #include "db.h"
