--- third_party/libjingle_xmpp/task_runner/taskrunner.cc.orig	2019-04-08 08:33:17 UTC
+++ third_party/libjingle_xmpp/task_runner/taskrunner.cc
@@ -80,7 +80,7 @@ void TaskRunner::InternalRunTasks(bool in_destructor) 
   std::vector<Task *>::iterator it;
   it = std::remove(tasks_.begin(),
                    tasks_.end(),
-                   reinterpret_cast<Task *>(NULL));
+                   static_cast<Task *>(NULL));
 
   tasks_.erase(it, tasks_.end());
   tasks_running_ = false;
