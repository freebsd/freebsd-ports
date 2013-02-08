--- watcher.h.orig	2013-01-28 21:38:20.000000000 +0800
+++ watcher.h	2013-01-28 21:38:27.000000000 +0800
@@ -131,7 +131,7 @@ void php_ev_set_watcher(ev_watcher *w, s
 void *php_ev_new_watcher(size_t size, zval *self, php_ev_loop *loop,
 		const zend_fcall_info *pfci, const zend_fcall_info_cache *pfcc, zval *data, int priority TSRMLS_DC);
 void php_ev_stop_watcher(ev_watcher *watcher TSRMLS_DC);
-inline void php_ev_set_watcher_priority(ev_watcher *watcher, long priority TSRMLS_DC);
+void php_ev_set_watcher_priority(ev_watcher *watcher, long priority TSRMLS_DC);
 void php_ev_start_watcher(ev_watcher *watcher TSRMLS_DC);
 
 #endif /* PHP_EV_WATCHER_H */
