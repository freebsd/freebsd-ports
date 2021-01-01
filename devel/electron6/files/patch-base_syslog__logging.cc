--- base/syslog_logging.cc.orig	2019-09-10 11:13:31 UTC
+++ base/syslog_logging.cc
@@ -9,7 +9,7 @@
 #include "base/bind.h"
 #include "base/callback_helpers.h"
 #include "base/debug/stack_trace.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // <syslog.h> defines LOG_INFO, LOG_WARNING macros that could conflict with
 // base::LOG_INFO, base::LOG_WARNING.
 #include <syslog.h>
@@ -94,7 +94,7 @@ EventLogMessage::~EventLogMessage() {
                     1, 0, strings, nullptr)) {
     stream() << " !!NOT ADDED TO EVENTLOG!!";
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   const char kEventSource[] = "chrome";
   openlog(kEventSource, LOG_NOWAIT | LOG_PID, LOG_USER);
   // We can't use the defined names for the logging severity from syslog.h
