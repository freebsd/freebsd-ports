--- src/php/ext/grpc/channel.c.orig	2020-11-03 05:45:42 UTC
+++ src/php/ext/grpc/channel.c
@@ -793,13 +793,13 @@ GRPC_STARTUP_FUNCTION(channel) {
   gpr_mu_init(&global_persistent_list_mu);
   le_plink = zend_register_list_destructors_ex(
       NULL, php_grpc_channel_plink_dtor, "Persistent Channel", module_number);
-  zend_hash_init_ex(&grpc_persistent_list, 20, NULL,
-                    EG(persistent_list).pDestructor, 1, 0);
+  zend_hash_init(&grpc_persistent_list, 20, NULL,
+                    EG(persistent_list).pDestructor, 1);
   // Register the target->upper_bound map.
   le_bound = zend_register_list_destructors_ex(
       NULL, php_grpc_target_bound_dtor, "Target Bound", module_number);
-  zend_hash_init_ex(&grpc_target_upper_bound_map, 20, NULL,
-                    EG(persistent_list).pDestructor, 1, 0);
+  zend_hash_init(&grpc_target_upper_bound_map, 20, NULL,
+                    EG(persistent_list).pDestructor, 1);
 
   PHP_GRPC_INIT_HANDLER(wrapped_grpc_channel, channel_ce_handlers);
   return SUCCESS;
