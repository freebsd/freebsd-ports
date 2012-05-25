--- ./applet/src/daisyTasks.cpp.orig	2010-11-09 19:29:47.000000000 -0500
+++ ./applet/src/daisyTasks.cpp	2012-05-24 02:56:20.000000000 -0400
@@ -159,7 +159,7 @@
 //-----------------------------------------------------------------------------
 // Startup added
 //FIXME
-void daisy::startupAdded(StartupPtr startupItem)
+void daisy::startupAdded(Startup* startupItem)
 {
   
   m_startingwindow = -1;
@@ -195,7 +195,7 @@
 //-----------------------------------------------------------------------------
 // Startup removed
 //FIXME
-void daisy::startupRemoved(StartupPtr startupItem)
+void daisy::startupRemoved(Startup* startupItem)
 {
   
   Q_UNUSED(startupItem);
@@ -218,7 +218,7 @@
   
   KWindowInfo taskInfo = KWindowSystem::windowInfo( id, NET::WMName | NET::WMVisibleName | NET::WMVisibleIconName | NET::WMState | NET::XAWMState | NET::WMDesktop, NET::WM2WindowClass );
   
-  TaskPtr task_tmp = TaskManager::TaskManager::self()->findTask( id );
+  Task* task_tmp = TaskManager::TaskManager::self()->findTask( id );
   
   
   if (  m_alias.indexOf( taskInfo.windowClassName() ) != -1 || m_alias.indexOf( QString(taskInfo.windowClassClass().toLower()) ) != -1 )
@@ -372,7 +372,7 @@
     KWindowInfo taskInfo = KWindowSystem::windowInfo( *it, NET::WMName | NET::WMVisibleName | NET::WMVisibleIconName | NET::WMState | NET::XAWMState | NET::WMDesktop | NET::WMWindowType, NET::WM2WindowClass );
     
     
-    TaskPtr task_tmp = TaskManager::TaskManager::self()->findTask( *it );
+    Task* task_tmp = TaskManager::TaskManager::self()->findTask( *it );
     if ( task_tmp && *it == KWindowSystem::activeWindow() )
     {m_focusedWindow = *it;}
     
@@ -478,7 +478,7 @@
 //-----------------------------------------------------------------------------
 // Create task thumbnail
 //FIXME
-void daisy::createTaskThumbnail( TaskPtr task_tmp, int j )
+void daisy::createTaskThumbnail( Task* task_tmp, int j )
 {
   QIcon thumbnail;
   //thumbnail = QIcon( QPixmap::grabWindow ( task_tmp->win(), 0, 0, -1, -1 ) );//This would suck
@@ -714,7 +714,7 @@
   KWindowInfo taskInfo = KWindowSystem::windowInfo( m_focusedWindow, NET::WMState, NET::WM2WindowClass );
   for (it = taskDict.begin(); it != taskDict.end(); ++it )
   {
-    TaskPtr task_tmp = TaskManager::TaskManager::self()->findTask( *it );
+    Task* task_tmp = TaskManager::TaskManager::self()->findTask( *it );
     if ( task_tmp ){real_taskDict << *it;}
   }
   if (real_taskDict.size() > 0)
@@ -768,7 +768,7 @@
 void daisy::delayTaskIcoChange(void)
 {
   m_uti_tmr->stop();
-  TaskPtr task_tmp = TaskManager::TaskManager::self()->findTask( m_toupwid );
+  Task* task_tmp = TaskManager::TaskManager::self()->findTask( m_toupwid );
   if ( task_tmp )
   {
 //     QIcon thumbnail;
