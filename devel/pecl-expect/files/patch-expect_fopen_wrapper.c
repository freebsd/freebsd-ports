--- expect_fopen_wrapper.c.orig	2020-01-13 18:27:49 UTC
+++ expect_fopen_wrapper.c
@@ -23,6 +23,10 @@
 #include "php_streams.h"
 #include <sys/wait.h>
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_DC
+#endif
+
 #if PHP_MAJOR_VERSION >= 7
 php_stream *php_expect_stream_open (php_stream_wrapper *wrapper, const char *command, const char *mode, int options, 
                            zend_string **opened_command, php_stream_context *context STREAMS_DC TSRMLS_DC)
