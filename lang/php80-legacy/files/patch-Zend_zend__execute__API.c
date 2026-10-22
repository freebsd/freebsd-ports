--- Zend/zend_execute_API.c.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_execute_API.c
@@ -334,10 +334,21 @@ void shutdown_executor(void) /* {{{ */
 			gc_collect_cycles();
 		}
 #endif
+	} else {
+		/* may be used by zend_error_zstr_at before init_executor */
+		ZVAL_UNDEF(&EG(user_error_handler));
+		ZVAL_UNDEF(&EG(user_exception_handler));
+		memset(&EG(user_error_handlers_error_reporting), 0, sizeof(EG(user_error_handlers_error_reporting)));
+		memset(&EG(user_error_handlers), 0, sizeof(EG(user_error_handlers)));
+		memset(&EG(user_exception_handlers), 0, sizeof(EG(user_exception_handlers)));
 	}
 
 	zend_objects_store_free_object_storage(&EG(objects_store), fast_shutdown);
 
+	/* may be used by zend_error_zstr_at before init_executor */
+	EG(error_handling) = EH_NORMAL;
+	EG(exception) = NULL;
+
 	zend_weakrefs_shutdown();
 
 	zend_try {
@@ -354,6 +365,8 @@ void shutdown_executor(void) /* {{{ */
 		zend_hash_discard(EG(function_table), EG(persistent_functions_count));
 		zend_hash_discard(EG(class_table), EG(persistent_classes_count));
 		zend_cleanup_internal_classes();
+		EG(objects_store).object_buckets = NULL;
+		EG(objects_store).top = 1;
 	} else {
 		zend_vm_stack_destroy();
 
