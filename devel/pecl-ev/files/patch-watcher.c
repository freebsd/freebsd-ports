--- watcher.c.orig	2013-01-28 21:38:15.000000000 +0800
+++ watcher.c	2013-01-28 21:38:24.000000000 +0800
@@ -27,7 +27,7 @@
 extern zend_class_entry *ev_loop_class_entry_ptr;
 
 /* {{{ php_ev_set_watcher_priority() */
-inline void php_ev_set_watcher_priority(ev_watcher *watcher, long priority TSRMLS_DC)
+void php_ev_set_watcher_priority(ev_watcher *watcher, long priority TSRMLS_DC)
 {
 	PHP_EV_CHECK_PENDING_WATCHER(watcher);	
 	ev_set_priority(watcher, priority);
