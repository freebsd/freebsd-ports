--- src/bthread/task_group.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/task_group.cpp
@@ -214,7 +214,7 @@ void TaskGroup::run_main_task() {
         }
         if (FLAGS_show_per_worker_usage_in_vars && !usage_bvar) {
             char name[32];
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
             snprintf(name, sizeof(name), "bthread_worker_usage_%" PRIu64,
                      pthread_numeric_id());
 #else
@@ -251,7 +251,7 @@ int PthreadAttrGetStack(void*& stack_addr, size_t& sta
 
 #ifdef BUTIL_USE_ASAN
 int PthreadAttrGetStack(void*& stack_addr, size_t& stack_size) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     stack_addr = pthread_get_stackaddr_np(pthread_self());
     stack_size = pthread_get_stacksize_np(pthread_self());
     return 0;
