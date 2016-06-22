--- src/plugins/projectexplorer/devicesupport/idevice.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/projectexplorer/devicesupport/idevice.cpp
@@ -30,6 +30,7 @@
 
 #include "../kit.h"
 #include "../kitinformation.h"
+#include "../runnables.h"
 
 #include <ssh/sshconnection.h>
 #include <utils/portlist.h>
@@ -466,4 +467,6 @@ DeviceEnvironmentFetcher::DeviceEnvironm
 {
 }
 
+void *HostName::staticTypeId = &HostName::staticTypeId;
+
 } // namespace ProjectExplorer
