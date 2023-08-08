--- libwzd-core/wzd_misc.h.orig	2023-02-11 11:24:33 UTC
+++ libwzd-core/wzd_misc.h
@@ -52,7 +52,7 @@ int split_filename(const char *filename, char *path, c
  * If the client is inside a function, it is stopped immediatly,
  * maybe creating some problems.
  */
-int kill_child_signal(unsigned long pid, wzd_context_t * context);
+int kill_child_signal(pthread_t pid, wzd_context_t * context);
 
 /** \brief Kill child
  *
@@ -61,7 +61,7 @@ int kill_child_signal(unsigned long pid, wzd_context_t
  * If the client is inside a function, it will exit after the function
  * is finished.
  */
-int kill_child_new(unsigned long pid, wzd_context_t * context);
+int kill_child_new(pthread_t pid, wzd_context_t * context);
 
 /* returns system ip on specifed interface (e.g eth0) */
 int get_system_ip(const char * itface, struct in_addr * ina);
