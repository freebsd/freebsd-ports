--- src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxManager.h.orig	2025-08-13 19:50:55 UTC
+++ src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxManager.h
@@ -341,6 +341,8 @@ private slots: (private)
       * @{ */
         /** Prepares window. */
         void prepare();
+        /** Prepares notification-center. */
+        void prepareNotificationCenter();
         /** Prepares cloud machine manager. */
         void prepareCloudMachineManager();
         /** Prepares icon. */
@@ -366,6 +368,8 @@ private slots: (private)
         void cleanupMenuBar();
         /** Cleanups cloud machine manager. */
         void cleanupCloudMachineManager();
+        /** Cleanups notification-center. */
+        void cleanupNotificationCenter();
         /** Cleanups window. */
         void cleanup();
     /** @} */
