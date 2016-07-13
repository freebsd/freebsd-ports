--- src/hal/hal_lib.c.orig	2016-06-25 02:19:12 UTC
+++ src/hal/hal_lib.c
@@ -2698,6 +2698,7 @@ void rtapi_app_exit(void)
 	/* and delete it */
 	free_thread_struct(thread);
     }
+    hal_data->base_period = 0;
     /* release mutex */
     rtapi_mutex_give(&(hal_data->mutex));
     /* release RTAPI resources */
