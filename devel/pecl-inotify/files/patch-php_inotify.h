--- php_inotify.h.orig	2020-10-24 21:00:19 UTC
+++ php_inotify.h
@@ -71,14 +71,25 @@ PHP_FUNCTION(inotify_read);
 #define INOTIFY_RM_WATCH_EINVAL \
 	"The file descriptor is not an inotify instance or the watch descriptor is invalid"
 
+#if PHP_MAJOR_VERSION >= 8
 #define INOTIFY_ERROR_CASE(func, errno) \
 	case (errno): \
+		php_error_docref(NULL, E_WARNING, INOTIFY_##func##_##errno); \
+		break;
+#define INOTIFY_DEFAULT_ERROR(errno) \
+	default: \
+		php_error_docref(NULL, E_WARNING, "%s", strerror(errno)); \
+		break;
+#else
+#define INOTIFY_ERROR_CASE(func, errno) \
+	case (errno): \
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, INOTIFY_##func##_##errno); \
 		break;
 #define INOTIFY_DEFAULT_ERROR(errno) \
 	default: \
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s", strerror(errno)); \
 		break;
+#endif
 
 
 #endif	/* PHP_INOTIFY_H */
