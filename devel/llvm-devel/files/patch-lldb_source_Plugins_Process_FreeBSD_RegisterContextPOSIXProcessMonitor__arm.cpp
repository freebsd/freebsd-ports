--- lldb/source/Plugins/Process/FreeBSD/RegisterContextPOSIXProcessMonitor_arm.cpp.orig
+++ lldb/source/Plugins/Process/FreeBSD/RegisterContextPOSIXProcessMonitor_arm.cpp
@@ -14,6 +14,7 @@
 #include "ProcessMonitor.h"
 #include "RegisterContextPOSIXProcessMonitor_arm.h"
 #include "Plugins/Process/Utility/RegisterContextPOSIX_arm.h"
+#include "Plugins/Process/Utility/lldb-arm-register-enums.h"
 
 using namespace lldb_private;
 using namespace lldb;
