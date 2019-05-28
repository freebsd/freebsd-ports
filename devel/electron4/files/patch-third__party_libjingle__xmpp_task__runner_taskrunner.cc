--- third_party/libjingle_xmpp/task_runner/taskrunner.cc.orig	2019-03-15 06:38:20 UTC
+++ third_party/libjingle_xmpp/task_runner/taskrunner.cc
@@ -95,7 +95,7 @@ void TaskRunner::InternalRunTasks(bool in_destructor) 
   std::vector<Task *>::iterator it;
   it = std::remove(tasks_.begin(),
                    tasks_.end(),
-                   reinterpret_cast<Task *>(NULL));
+                   static_cast<Task *>(NULL));
 
   tasks_.erase(it, tasks_.end());
 
