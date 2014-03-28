--- src/liboyranos_core/oyranos_threads.c.orig	2014-03-13 22:06:34.153920114 +0400
+++ src/liboyranos_core/oyranos_threads.c	2014-03-13 22:07:12.182505283 +0400
@@ -181,9 +181,11 @@
     oyObject_Lock( oy_job_message_list_->oy_, __func__, __LINE__ );
     oyObject_UnLock( oy_job_message_list_->oy_, __func__, __LINE__ );
 
+#ifdef _OPENMP
     if((omp_get_num_procs() - 1) >= 1)
       oy_thread_count_ = omp_get_num_procs() - 1;
     else
+#endif
       oy_thread_count_ = 1;
 
     oy_threads_ = (oyThread_t*)calloc(sizeof(oyThread_t),oy_thread_count_+1);
