--- src/shims/time.h.orig	2011-09-08 23:49:45.000000000 -0700
+++ src/shims/time.h	2011-09-08 23:49:56.000000000 -0700
@@ -52,8 +52,8 @@
 	bool ratio_1_to_1;
 	dispatch_once_t pred;
 } _dispatch_host_time_data_s;
-__private_extern__ _dispatch_host_time_data_s _dispatch_host_time_data;
-__private_extern__ void _dispatch_get_host_time_init(void *context);
+extern _dispatch_host_time_data_s _dispatch_host_time_data;
+extern void _dispatch_get_host_time_init(void *context);
 
 static inline uint64_t
 _dispatch_time_mach2nano(uint64_t machtime)
