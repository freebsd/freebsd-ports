--- ./applet/src/daisy.h.orig	2010-06-29 09:11:50.000000000 -0400
+++ ./applet/src/daisy.h	2012-05-24 02:54:47.000000000 -0400
@@ -102,8 +102,8 @@
 #include <taskmanager/taskitem.h>
 #include <taskmanager/groupmanager.h>
 #include <taskmanager/startup.h>
-using TaskManager::TaskPtr;
-using TaskManager::StartupPtr;
+using TaskManager::Task;
+using TaskManager::Startup;
 using TaskManager::GroupManager;
 
 
@@ -337,7 +337,7 @@
     bool checkLock();
     
     void checkAttention( KWindowInfo taskInfo, QString widclass_tmp );
-    void createTaskThumbnail( TaskPtr task_tmp, int j );
+    void createTaskThumbnail( Task* task_tmp, int j );
     void scrollTasks(int delta);
     
     
@@ -418,7 +418,7 @@
     QSizeF m_hoversz;
     
     
-    TaskPtr m_task;
+    Task* m_task;
     GroupManager *m_groupManager;
     
     
@@ -512,8 +512,8 @@
   private slots:
     
     
-    void startupAdded(StartupPtr startupItem);
-    void startupRemoved(StartupPtr startupItem);
+    void startupAdded(Startup* startupItem);
+    void startupRemoved(Startup* startupItem);
     
     
     void windowAdded(WId id);
