--- include/logtype.h.orig	Tue Feb  6 14:48:29 2007
+++ include/logtype.h	Tue Feb  6 14:49:21 2007
@@ -34,14 +34,14 @@
 #define LOG_PROXYLOG	0x40	/* Element is logged to the proxy logfile */
 #define LOG_HTTPLOG	0x80	/* Element is logged to the http logfile */
 
-#define LOG_FN_LOGFILE	IRCD_PREFIX_VAR "/log/" BASENAME "/events.log"
-#define LOG_FN_IRCLOG	IRCD_PREFIX_VAR "/log/" BASENAME "/ircd.log"
-#define LOG_FN_DEBUGLOG	IRCD_PREFIX_VAR "/log/" BASENAME "/debug.log"
-#define LOG_FN_ERRORLOG	IRCD_PREFIX_VAR "/log/" BASENAME "/error.log"
-#define LOG_FN_STDERR	IRCD_PREFIX_VAR "/log/" BASENAME "/stderr.log"
-#define LOG_FN_STDOUT	IRCD_PREFIX_VAR "/log/" BASENAME "/stdout.log"
-#define LOG_FN_PROXY	IRCD_PREFIX_VAR "/log/" BASENAME "/proxy.log"
-#define LOG_FN_HTTPD	IRCD_PREFIX_VAR "/log/" BASENAME "/httpd.log"
+#define LOG_FN_LOGFILE	IRCD_PREFIX_LOG "/events.log"
+#define LOG_FN_IRCLOG	IRCD_PREFIX_LOG "/ircd.log"
+#define LOG_FN_DEBUGLOG	IRCD_PREFIX_LOG "/debug.log"
+#define LOG_FN_ERRORLOG	IRCD_PREFIX_LOG "/error.log"
+#define LOG_FN_STDERR	IRCD_PREFIX_LOG "/stderr.log"
+#define LOG_FN_STDOUT	IRCD_PREFIX_LOG "/stdout.log"
+#define LOG_FN_PROXY	IRCD_PREFIX_LOG "/proxy.log"
+#define LOG_FN_HTTPD	IRCD_PREFIX_LOG "/httpd.log"
 
 #define LOG_FATAL	-2	/* Element is to be logged always */
 #define LOG_ERROR	-1	/* Element has error level logging */
