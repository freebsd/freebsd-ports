--- Source_Files/Misc/Logging_gruntwork.h.orig	Tue Aug 30 23:47:00 2005
+++ Source_Files/Misc/Logging_gruntwork.h	Tue Apr 18 12:27:12 2006
@@ -13,14 +13,14 @@
 #define logDump(message)	(GetCurrentLogger()->logMessage(logDomain, logDumpLevel, __FILE__, __LINE__, (message)))
 #else
 // this obsoletes this whole file, pretty much - since macros can support var args and stuff :P
-#define logFatal(...)    (GetCurrentLogger()->logMessage(logDomain, logFatalLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logError(...)    (GetCurrentLogger()->logMessage(logDomain, logErrorLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logWarning(...)  (GetCurrentLogger()->logMessage(logDomain, logWarningLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logAnomaly(...)  (GetCurrentLogger()->logMessage(logDomain, logAnomalyLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logNote(...)     (GetCurrentLogger()->logMessage(logDomain, logNoteLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logSummary(...)  (GetCurrentLogger()->logMessage(logDomain, logSummaryLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logTrace(...)    (GetCurrentLogger()->logMessage(logDomain, logTraceLevel, __FILE__, __LINE__, __VA_ARGS__))
-#define logDump(...)     (GetCurrentLogger()->logMessage(logDomain, logDumpLevel, __FILE__, __LINE__, __VA_ARGS__))
+#define logFatal(ARGS...)    (GetCurrentLogger()->logMessage(logDomain, logFatalLevel, __FILE__, __LINE__, ##ARGS))
+#define logError(ARGS...)    (GetCurrentLogger()->logMessage(logDomain, logErrorLevel, __FILE__, __LINE__, ##ARGS))
+#define logWarning(ARGS...)  (GetCurrentLogger()->logMessage(logDomain, logWarningLevel, __FILE__, __LINE__, ##ARGS))
+#define logAnomaly(ARGS...)  (GetCurrentLogger()->logMessage(logDomain, logAnomalyLevel, __FILE__, __LINE__, ##ARGS))
+#define logNote(ARGS...)     (GetCurrentLogger()->logMessage(logDomain, logNoteLevel, __FILE__, __LINE__, ##ARGS))
+#define logSummary(ARGS...)  (GetCurrentLogger()->logMessage(logDomain, logSummaryLevel, __FILE__, __LINE__, ##ARGS))
+#define logTrace(ARGS...)    (GetCurrentLogger()->logMessage(logDomain, logTraceLevel, __FILE__, __LINE__, ##ARGS))
+#define logDump(ARGS...)     (GetCurrentLogger()->logMessage(logDomain, logDumpLevel, __FILE__, __LINE__, ##ARGS))
 #endif
 
 
