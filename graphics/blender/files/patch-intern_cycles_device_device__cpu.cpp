--- intern/cycles/device/device_cpu.cpp.orig	2021-01-21 07:59:12 UTC
+++ intern/cycles/device/device_cpu.cpp
@@ -927,7 +927,7 @@ class CPUDevice : public Device {
     SIMD_SET_FLUSH_TO_ZERO;

     for (int sample = start_sample; sample < end_sample; sample++) {
-      if (task.get_cancel() || task_pool.canceled()) {
+      if (task.get_cancel() || TaskPool::canceled()) {
         if (task.need_finish_queue == false)
           break;
       }
@@ -1220,7 +1220,7 @@ class CPUDevice : public Device {

   void thread_render(DeviceTask &task)
   {
-    if (task_pool.canceled()) {
+    if (TaskPool::canceled()) {
       if (task.need_finish_queue == false)
         return;
     }
@@ -1290,7 +1290,7 @@ class CPUDevice : public Device {

       task.release_tile(tile);

-      if (task_pool.canceled()) {
+      if (TaskPool::canceled()) {
         if (task.need_finish_queue == false)
           break;
       }
@@ -1387,7 +1387,7 @@ class CPUDevice : public Device {
                         task.offset,
                         sample);

-      if (task.get_cancel() || task_pool.canceled())
+      if (task.get_cancel() || TaskPool::canceled())
         break;

       task.update_progress(NULL);
