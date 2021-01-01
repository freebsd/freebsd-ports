--- src/plugins/cdda/cdda.c.orig	2011-10-20 19:26:08 UTC
+++ src/plugins/cdda/cdda.c
@@ -18,7 +18,7 @@
 #include "xmms/xmms_log.h"
 #include "xmms/xmms_util.h"
 
-#include <cdio/cdda.h>
+#include <cdio/paranoia/cdda.h>
 #include <cdio/cdio.h>
 #include <cdio/logging.h>
 #include <discid/discid.h>
