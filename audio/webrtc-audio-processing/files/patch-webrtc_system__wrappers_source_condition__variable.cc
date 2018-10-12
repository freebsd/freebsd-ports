- Match conditional in webrtc/system_wrappers/Makefile.am

--- webrtc/system_wrappers/source/condition_variable.cc.orig	2018-07-23 14:02:57 UTC
+++ webrtc/system_wrappers/source/condition_variable.cc
@@ -14,7 +14,7 @@
 #include <windows.h>
 #include "webrtc/system_wrappers/source/condition_variable_event_win.h"
 #include "webrtc/system_wrappers/source/condition_variable_native_win.h"
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_POSIX)
 #include <pthread.h>
 #include "webrtc/system_wrappers/source/condition_variable_posix.h"
 #endif
@@ -31,7 +31,7 @@ ConditionVariableWrapper* ConditionVariableWrapper::Cr
     ret_val = new ConditionVariableEventWin();
   }
   return ret_val;
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_POSIX)
   return ConditionVariablePosix::Create();
 #else
   return NULL;
