--- libwzd-core/wzd_structs.h.orig	2007-05-17 09:54:38 UTC
+++ libwzd-core/wzd_structs.h
@@ -366,8 +366,8 @@ struct wzd_context_t {
   data_mode_t   datamode;
   tls_data_mode_t    tls_data_mode;
   net_family_t  datafamily; /**< \brief IPv4 or IPv6 */
-  unsigned long	pid_child;
-  unsigned long	thread_id;
+  pthread_t	pid_child;
+  pthread_t	thread_id;
 
   union wzd_thread_t * transfer_thread;
   u8_t          is_transferring;
