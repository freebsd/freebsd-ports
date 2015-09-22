--- src/cl_api.c.orig	2015-02-03 14:58:29.071589000 +0100
+++ src/cl_api.c	2015-02-03 14:58:39.124158000 +0100
@@ -64,7 +64,7 @@
 	  return RET; \
 	} while(0)
 
-inline cl_int
+static inline cl_int
 handle_events(cl_command_queue queue, cl_int num, const cl_event *wait_list,
               cl_event* event, enqueue_data* data, cl_command_type type)
 {
