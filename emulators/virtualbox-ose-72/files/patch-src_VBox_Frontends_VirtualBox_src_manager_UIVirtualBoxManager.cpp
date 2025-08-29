--- src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxManager.cpp.orig	2025-08-13 19:50:55 UTC
+++ src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxManager.cpp
@@ -2402,6 +2402,9 @@ void UIVirtualBoxManager::prepare()
     qApp->installEventFilter(this);
 #endif
 
+   /* Prepare notification-center invisibvle way: */
+    prepareNotificationCenter();
+
     /* Cache media data early if necessary: */
     if (uiCommon().agressiveCaching())
         gpMediumEnumerator->enumerateMedia();
@@ -2446,6 +2449,12 @@ void UIVirtualBoxManager::prepare()
 #endif /* VBOX_GUI_WITH_NETWORK_MANAGER && VBOX_WITH_UPDATE_REQUEST */
 }
 
+void UIVirtualBoxManager::prepareNotificationCenter()
+{
+    UINotificationCenter::create();
+
+}
+
 void UIVirtualBoxManager::prepareCloudMachineManager()
 {
     UICloudMachineManager::create();
@@ -2805,6 +2814,12 @@ void UIVirtualBoxManager::cleanupCloudMachineManager()
     UICloudMachineManager::destroy();
 }
 
+void UIVirtualBoxManager::cleanupNotificationCenter()
+{
+    UINotificationCenter::destroy();
+
+}
+
 void UIVirtualBoxManager::cleanup()
 {
     /* Ask sub-dialogs to commit data: */
@@ -2814,6 +2829,7 @@ void UIVirtualBoxManager::cleanup()
     cleanupWidgets();
     cleanupMenuBar();
     cleanupCloudMachineManager();
+    cleanupNotificationCenter();
 }
 
 UIVirtualMachineItem *UIVirtualBoxManager::currentItem() const
