--- php_uv.c.orig	2019-05-01 11:04:19 UTC
+++ php_uv.c
@@ -17,6 +17,7 @@
    +----------------------------------------------------------------------+
  */
 
+#pragma GCC diagnostic ignored "-Wmissing-braces"
 
 #include "php_uv.h"
 #include "php_main.h"
@@ -294,7 +295,11 @@ static int uv_parse_arg_object(zval *arg, zval **dest,
 #endif
 
 #if !defined(PHP_WIN32) && !(defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS))
+# if PHP_VERSION_ID >= 80000
+zend_class_entry *(*socket_ce)(void) = NULL;
+# else
 int (*php_sockets_le_socket)(void) = NULL;
+# endif
 #endif
 
 /* objects */
@@ -446,7 +451,7 @@ static php_socket_t php_uv_zval_to_valid_poll_fd(zval 
 			}
 
 			fd = -1;
-#if !defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS))
+#if PHP_VERSION_ID < 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS)))
 		} else if (php_sockets_le_socket && (socket = (php_socket *) zend_fetch_resource_ex(ptr, NULL, php_sockets_le_socket()))) {
 			fd = socket->bsd_socket;
 #endif
@@ -454,6 +459,10 @@ static php_socket_t php_uv_zval_to_valid_poll_fd(zval 
 			php_error_docref(NULL, E_WARNING, "unhandled resource type detected.");
 			fd = -1;
 		}
+#if PHP_VERSION_ID >= 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS)))
+	} else if (socket_ce && Z_TYPE_P(ptr) == IS_OBJECT && Z_OBJCE_P(ptr) == socket_ce && (socket = (php_socket *) ((char *)(Z_OBJ_P(ptr)) - XtOffsetOf(php_socket, std)))) {
+		fd = socket->bsd_socket;
+#endif
 	}
 
 	return fd;
@@ -472,7 +481,7 @@ static php_socket_t php_uv_zval_to_fd(zval *ptr)
 			if (php_stream_cast(stream, PHP_STREAM_AS_FD | PHP_STREAM_CAST_INTERNAL, (void *) &fd, 1) != SUCCESS || fd < 0) {
 				fd = -1;
 			}
-#if !defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS))
+#if PHP_VERSION_ID < 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS)))
 		} else if (php_sockets_le_socket && (socket = (php_socket *) zend_fetch_resource_ex(ptr, NULL, php_sockets_le_socket()))) {
 			fd = socket->bsd_socket;
 #endif
@@ -494,6 +503,10 @@ static php_socket_t php_uv_zval_to_fd(zval *ptr)
 				fd = -1;
 			}
 		}
+#if PHP_VERSION_ID >= 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS)))
+	} else if (socket_ce && Z_TYPE_P(ptr) == IS_OBJECT && Z_OBJCE_P(ptr) == socket_ce && (socket = (php_socket *) ((char *)(Z_OBJ_P(ptr)) - XtOffsetOf(php_socket, std)))) {
+		fd = socket->bsd_socket;
+#endif
 	}
 
 	return fd;
@@ -1099,7 +1112,7 @@ static void php_uv_fs_common(uv_fs_type fs_type, INTER
 
 static zval php_uv_address_to_zval(const struct sockaddr *addr)
 {
-	zval tmp = {{0}};
+	zval tmp = {0};
 	char ip[INET6_ADDRSTRLEN];
 	const struct sockaddr_in *a4;
 	const struct sockaddr_in6 *a6;
@@ -1139,7 +1152,7 @@ static zval php_uv_address_to_zval(const struct sockad
 
 static zval php_uv_make_stat(const uv_stat_t *s)
 {
-	zval tmp = {{0}};
+	zval tmp = {0};
 	array_init(&tmp);
 
 	add_assoc_long_ex(&tmp, ZEND_STRL("dev"), s->st_dev);
@@ -1305,7 +1318,9 @@ static int php_uv_do_callback(zval *retval_ptr, php_uv
 		callback->fci.params = params;
 		callback->fci.retval = retval_ptr;
 		callback->fci.param_count = param_count;
+#if PHP_VERSION_ID < 80000
 		callback->fci.no_separation = 1;
+#endif
 
 		error = zend_call_function(&callback->fci, &callback->fcc);
 	} else {
@@ -1330,7 +1345,9 @@ static int php_uv_do_callback2(zval *retval_ptr, php_u
 		uv->callback[type]->fci.params        = params;
 		uv->callback[type]->fci.retval        = retval_ptr;
 		uv->callback[type]->fci.param_count   = param_count;
+#if PHP_VERSION_ID < 80000
 		uv->callback[type]->fci.no_separation = 1;
+#endif
 
 		if (zend_call_function(&uv->callback[type]->fci, &uv->callback[type]->fcc) != SUCCESS) {
 			error = -1;
@@ -1370,7 +1387,9 @@ static int php_uv_do_callback3(zval *retval_ptr, php_u
 		uv->callback[type]->fci.params        = params;
 		uv->callback[type]->fci.retval        = retval_ptr;
 		uv->callback[type]->fci.param_count   = param_count;
+#if PHP_VERSION_ID < 80000
 		uv->callback[type]->fci.no_separation = 1;
+#endif
 		uv->callback[type]->fci.object = NULL;
 #if PHP_VERSION_ID >= 70300
 		uv->callback[type]->fci.size = sizeof(zend_fcall_info);
@@ -1432,8 +1451,8 @@ static int php_uv_do_callback3(zval *retval_ptr, php_u
 
 static void php_uv_tcp_connect_cb(uv_connect_t *req, int status)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t *) req->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1453,8 +1472,8 @@ static void php_uv_tcp_connect_cb(uv_connect_t *req, i
 /* TODO: Not sure how PHP will deal with int64_t */
 static void php_uv_process_close_cb(uv_process_t* process, int64_t exit_status, int term_signal)
 {
-	zval retval = {{0}};
-	zval params[3] = {{{0}}};
+	zval retval = {0};
+	zval params[3] = {0};
 	php_uv_t *uv = (php_uv_t*)process->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1475,8 +1494,8 @@ static void php_uv_process_close_cb(uv_process_t* proc
 
 static void php_uv_pipe_connect_cb(uv_connect_t *req, int status)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t*)req->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1497,8 +1516,8 @@ static void php_uv_pipe_connect_cb(uv_connect_t *req, 
 static void php_uv_walk_cb(uv_handle_t* handle, void* arg)
 {
 /*
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
 	ZVAL_LONG(&params[0], status);
@@ -1516,8 +1535,8 @@ static void php_uv_walk_cb(uv_handle_t* handle, void* 
 static void php_uv_write_cb(uv_write_t* req, int status)
 {
 	write_req_t* wr = (write_req_t*) req;
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t *) req->handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1540,8 +1559,8 @@ static void php_uv_write_cb(uv_write_t* req, int statu
 static void php_uv_udp_send_cb(uv_udp_send_t* req, int status)
 {
 	send_req_t* wr = (send_req_t*) req;
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t *) req->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1566,8 +1585,8 @@ static void php_uv_udp_send_cb(uv_udp_send_t* req, int
 
 static void php_uv_listen_cb(uv_stream_t* server, int status)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t *) server->data;
 
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -1588,8 +1607,8 @@ static void php_uv_listen_cb(uv_stream_t* server, int 
 
 static void php_uv_shutdown_cb(uv_shutdown_t* handle, int status)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t *) handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1607,8 +1626,8 @@ static void php_uv_shutdown_cb(uv_shutdown_t* handle, 
 
 static void php_uv_read_cb(uv_stream_t* handle, ssize_t nread, const uv_buf_t* buf)
 {
-	zval retval = {{0}};
-	zval params[3] = {{{0}}};
+	zval retval = {0};
+	zval params[3] = {0};
 	php_uv_t *uv = (php_uv_t *) handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1644,8 +1663,8 @@ static void php_uv_read_cb(uv_stream_t* handle, ssize_
 /* unused
 static void php_uv_read2_cb(uv_pipe_t* handle, ssize_t nread, uv_buf_t buf, uv_handle_type pending)
 {
-	zval retval = {{0}};
-	zval params[4] = {{{0}}};
+	zval retval = {0};
+	zval params[4] = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1682,7 +1701,7 @@ static void php_uv_read2_cb(uv_pipe_t* handle, ssize_t
 
 static void php_uv_prepare_cb(uv_prepare_t* handle)
 {
-	zval retval = {{0}};
+	zval retval = {0};
 	zval params[1];
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -1703,7 +1722,7 @@ static void php_uv_prepare_cb(uv_prepare_t* handle)
 
 static void php_uv_check_cb(uv_check_t* handle)
 {
-	zval retval = {{0}};
+	zval retval = {0};
 	zval params[1];
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -1725,7 +1744,7 @@ static void php_uv_check_cb(uv_check_t* handle)
 
 static void php_uv_async_cb(uv_async_t* handle)
 {
-	zval retval = {{0}};
+	zval retval = {0};
 	zval params[1];
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -1747,7 +1766,7 @@ static void php_uv_async_cb(uv_async_t* handle)
 #if defined(ZTS) && PHP_VERSION_ID < 80000
 static void php_uv_work_cb(uv_work_t* req)
 {
-	zval retval = {{0}};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)req->data;
 
 	uv = (php_uv_t*)req->data;
@@ -1759,7 +1778,7 @@ static void php_uv_work_cb(uv_work_t* req)
 
 static void php_uv_after_work_cb(uv_work_t* req, int status)
 {
-	zval retval = {{0}};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)req->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1779,8 +1798,8 @@ static void php_uv_after_work_cb(uv_work_t* req, int s
 
 static void php_uv_fs_cb(uv_fs_t* req)
 {
-	zval params[3] = {{{0}}};
-	zval retval = {{0}};
+	zval params[3] = {0};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)req->data;
 	int argc, i = 0;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -1928,8 +1947,8 @@ static void php_uv_fs_cb(uv_fs_t* req)
 
 static void php_uv_fs_event_cb(uv_fs_event_t* req, const char* filename, int events, int status)
 {
-	zval params[4] = {{{0}}};
-	zval retval = {{0}};
+	zval params[4] = {0};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)req->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -1959,7 +1978,7 @@ static void php_uv_fs_event_cb(uv_fs_event_t* req, con
 
 static zval php_uv_stat_to_zval(const uv_stat_t *stat)
 {
-	zval result = {{0}};
+	zval result = {0};
 	array_init(&result);
 
 	add_assoc_long_ex(&result, ZEND_STRL("dev"), stat->st_dev);
@@ -1985,8 +2004,8 @@ static zval php_uv_stat_to_zval(const uv_stat_t *stat)
 
 static void php_uv_fs_poll_cb(uv_fs_poll_t* handle, int status, const uv_stat_t* prev, const uv_stat_t* curr)
 {
-	zval params[4] = {{{0}}};
-	zval retval = {{0}};
+	zval params[4] = {0};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -2010,8 +2029,8 @@ static void php_uv_fs_poll_cb(uv_fs_poll_t* handle, in
 
 static void php_uv_poll_cb(uv_poll_t* handle, int status, int events)
 {
-	zval params[4] = {{{0}}};
-	zval retval = {{0}};
+	zval params[4] = {0};
+	zval retval = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -2043,8 +2062,8 @@ static void php_uv_poll_cb(uv_poll_t* handle, int stat
 static void php_uv_udp_recv_cb(uv_udp_t* handle, ssize_t nread, const uv_buf_t* buf, const struct sockaddr* addr, unsigned flags)
 {
 	/* TODO: is this correctly implmented? */
-	zval retval = {{0}};
-	zval params[3] = {{{0}}};
+	zval retval = {0};
+	zval params[3] = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -2077,8 +2096,8 @@ static void php_uv_read_alloc(uv_handle_t* handle, siz
 
 static void php_uv_close_cb(uv_handle_t *handle)
 {
-	zval retval = {{0}};
-	zval params[1] = {{{0}}};
+	zval retval = {0};
+	zval params[1] = {0};
 
 	php_uv_t *uv = (php_uv_t *) handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -2119,8 +2138,8 @@ static void php_uv_close(php_uv_t *uv) {
 
 static void php_uv_idle_cb(uv_timer_t *handle)
 {
-	zval retval = {{0}};
-	zval params[1] = {{{0}}};
+	zval retval = {0};
+	zval params[1] = {0};
 
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
@@ -2139,8 +2158,8 @@ static void php_uv_idle_cb(uv_timer_t *handle)
 
 static void php_uv_getaddrinfo_cb(uv_getaddrinfo_t* handle, int status, struct addrinfo* res)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	struct addrinfo *address;
 	char ip[INET6_ADDRSTRLEN];
 	const char *addr;
@@ -2186,8 +2205,8 @@ static void php_uv_getaddrinfo_cb(uv_getaddrinfo_t* ha
 
 static void php_uv_timer_cb(uv_timer_t *handle)
 {
-	zval retval = {{0}};
-	zval params[1] = {{{0}}};
+	zval retval = {0};
+	zval params[1] = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -2208,8 +2227,8 @@ static void php_uv_timer_cb(uv_timer_t *handle)
 
 static void php_uv_signal_cb(uv_signal_t *handle, int sig_num)
 {
-	zval retval = {{0}};
-	zval params[2] = {{{0}}};
+	zval retval = {0};
+	zval params[2] = {0};
 	php_uv_t *uv = (php_uv_t*)handle->data;
 	TSRMLS_FETCH_FROM_CTX(uv->thread_ctx);
 
@@ -2419,7 +2438,7 @@ static void php_uv_tcp_connect(enum php_uv_socket_type
 /* zend */
 
 static zend_function_entry php_uv_empty_methods[] = {
-	{NULL, NULL, NULL}
+	{0}
 };
 
 #if PHP_VERSION_ID >= 80000
@@ -2676,10 +2695,17 @@ PHP_MINIT_FUNCTION(uv)
 		zend_module_entry *sockets;
 		if ((sockets = zend_hash_str_find_ptr(&module_registry, ZEND_STRL("sockets")))) {
 			if (sockets->handle) { // shared
+# if PHP_VERSION_ID >= 80000
+				socket_ce = (int (*)(void)) DL_FETCH_SYMBOL(sockets->handle, "_socket_ce");
+				if (socket_ce == NULL) {
+					socket_ce = (int (*)(void)) DL_FETCH_SYMBOL(sockets->handle, "_socket_ce");
+				}
+# else
 				php_sockets_le_socket = (int (*)(void)) DL_FETCH_SYMBOL(sockets->handle, "php_sockets_le_socket");
 				if (php_sockets_le_socket == NULL) {
 					php_sockets_le_socket = (int (*)(void)) DL_FETCH_SYMBOL(sockets->handle, "_php_sockets_le_socket");
 				}
+#endif
 			}
 		}
 	}
@@ -4775,7 +4801,7 @@ PHP_FUNCTION(uv_stdio_new)
 				php_error_docref(NULL, E_WARNING, "passed resource without file descriptor");
 				RETURN_FALSE;
 			}
-#if !defined(PHP_WIN32) || defined(HAVE_SOCKET)
+#if PHP_VERSION_ID < 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKET) && !defined(COMPILE_DL_SOCKETS)))
 		} else if ((socket = (php_socket *) zend_fetch_resource_ex(handle, NULL, php_sockets_le_socket()))) {
 			fd = socket->bsd_socket;
 #endif
@@ -4797,8 +4823,17 @@ PHP_FUNCTION(uv_stdio_new)
 			php_error_docref(NULL, E_WARNING, "flags must be exactly one of UV::INHERIT_STREAM or UV::CREATE_PIPE for UV handles");
 			RETURN_FALSE;
 		}
+#if PHP_VERSION_ID >= 80000 && (!defined(PHP_WIN32) || (defined(HAVE_SOCKETS) && !defined(COMPILE_DL_SOCKETS)))
+	} else if (socket_ce && Z_TYPE_P(handle) == IS_OBJECT && Z_OBJCE_P(handle) == socket_ce && (socket = (php_socket *) ((char *)(Z_OBJ_P(handle)) - XtOffsetOf(php_socket, std)))) {
+		fd = socket->bsd_socket;
+		if (flags & (UV_CREATE_PIPE | UV_INHERIT_STREAM)) {
+			php_error_docref(NULL, E_WARNING, "flags must not be UV::CREATE_PIPE or UV::INHERIT_STREAM for socket objects");
+			RETURN_FALSE;
+		}
+		flags |= UV_INHERIT_FD;
+#endif
 	} else {
-		php_error_docref(NULL, E_WARNING, "passed unexpected value, expected instance of UV, file resource or socket resource");
+		php_error_docref(NULL, E_WARNING, "passed unexpected value, expected instance of UV, file resource or socket object");
 		RETURN_FALSE;
 	}
 
@@ -6331,7 +6366,7 @@ static zend_function_entry uv_functions[] = {
 	PHP_FE(uv_signal_init,              arginfo_uv_signal_init)
 	PHP_FE(uv_signal_start,             arginfo_uv_signal_start)
 	PHP_FE(uv_signal_stop,              arginfo_uv_signal_stop)
-	{NULL, NULL, NULL}
+	{0}
 };
 
 PHP_MINFO_FUNCTION(uv)
