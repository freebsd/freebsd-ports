--- php_zookeeper_log.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper_log.c
@@ -19,17 +19,10 @@
 #include <zookeeper_log.h> /* Symbol LOG_INFO defined in this file conflicts with the symbol defined in syslog.h */
 #include "php_zookeeper_log.h"
 
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 #define PHP_ZK_LOG_ERROR(_zh, ...) LOG_ERROR(LOGCALLBACK(_zh), __VA_ARGS__)
 #define PHP_ZK_LOG_WARN(_zh, ...) LOG_WARN(LOGCALLBACK(_zh), __VA_ARGS__)
 #define PHP_ZK_LOG_INFO(_zh, ...) LOG_INFO(LOGCALLBACK(_zh), __VA_ARGS__)
 #define PHP_ZK_LOG_DEBUG(_zh, ...) LOG_DEBUG(LOGCALLBACK(_zh), __VA_ARGS__)
-#else
-#define PHP_ZK_LOG_ERROR(_zh, ...) LOG_ERROR((__VA_ARGS__))
-#define PHP_ZK_LOG_WARN(_zh, ...) LOG_WARN((__VA_ARGS__))
-#define PHP_ZK_LOG_INFO(_zh, ...) LOG_INFO((__VA_ARGS__))
-#define PHP_ZK_LOG_DEBUG(_zh, ...) LOG_DEBUG((__VA_ARGS__))
-#endif
 
 #define PHP_ZK_LOG_FUNC(func, FUNC) \
 	void php_zk_log_##func(zhandle_t *zh, ...)	\
