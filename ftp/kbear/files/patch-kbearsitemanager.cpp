--- kbear/plugins/sitemanager/kbearsitemanager.cpp.orig	Wed May 29 21:02:54 2002
+++ kbear/plugins/sitemanager/kbearsitemanager.cpp	Wed May 29 21:02:57 2002
@@ -46,6 +46,7 @@
 #include "../../base/group.h"
 #include "../../base/siteimportfilterpluginiface.h"
 #include <netdb.h>
+#include <sys/param.h>
 #include <netinet/in.h>
 #include <string.h>
 
