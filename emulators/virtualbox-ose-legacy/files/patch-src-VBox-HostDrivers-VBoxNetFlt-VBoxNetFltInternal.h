Index: src/VBox/HostDrivers/VBoxNetFlt/VBoxNetFltInternal.h
===================================================================
--- src/VBox/HostDrivers/VBoxNetFlt/VBoxNetFltInternal.h	(revision 23391)
+++ src/VBox/HostDrivers/VBoxNetFlt/VBoxNetFltInternal.h	(working copy)
@@ -206,6 +206,14 @@
             hook_p output;
             /** Original interface flags */
             unsigned int flags;
+            /** Input queue */
+            struct ifqueue inq;
+            /** Output queue */
+            struct ifqueue outq;
+            /** Input task */
+            struct task tskin;
+            /** Output task */
+            struct task tskout;
             /** The MAC address of the interface. */
             RTMAC Mac;
             /** @} */
@@ -241,6 +249,8 @@
 # endif
 #elif defined(RT_OS_LINUX)
         uint8_t abPadding[320];
+#elif defined(RT_OS_FREEBSD)
+        uint8_t abPadding[320];
 #else
         uint8_t abPadding[128];
 #endif
