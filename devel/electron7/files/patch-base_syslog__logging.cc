--- base/syslog_logging.cc.orig	2019-12-12 12:38:59 UTC
+++ base/syslog_logging.cc
@@ -14,7 +14,7 @@
 #include "base/debug/stack_trace.h"
 #include "base/strings/string_util.h"
 #include "base/win/win_util.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // <syslog.h> defines LOG_INFO, LOG_WARNING macros that could conflict with
 // base::LOG_INFO, base::LOG_WARNING.
 #include <syslog.h>
@@ -113,7 +113,7 @@ EventLogMessage::~EventLogMessage() {
 
   if (user_sid != nullptr)
     ::LocalFree(user_sid);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   const char kEventSource[] = "chrome";
   openlog(kEventSource, LOG_NOWAIT | LOG_PID, LOG_USER);
   // We can't use the defined names for the logging severity from syslog.h
