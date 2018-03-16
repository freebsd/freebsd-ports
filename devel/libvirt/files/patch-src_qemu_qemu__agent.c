--- src/qemu/qemu_agent.c.orig	2018-02-26 09:02:18 UTC
+++ src/qemu/qemu_agent.c
@@ -53,6 +53,15 @@ VIR_LOG_INIT("qemu.qemu_agent");
 #define DEBUG_IO 0
 #define DEBUG_RAW_IO 0
 
+/* We read from QEMU until seeing a \r\n pair to indicate a
+ * completed reply or event. To avoid memory denial-of-service
+ * though, we must have a size limit on amount of data we
+ * buffer. 10 MB is large enough that it ought to cope with
+ * normal QEMU replies, and small enough that we're not
+ * consuming unreasonable mem.
+ */
+#define QEMU_AGENT_MAX_RESPONSE (10 * 1024 * 1024)
+
 /* When you are the first to uncomment this,
  * don't forget to uncomment the corresponding
  * part in qemuAgentIOProcessEvent as well.
@@ -535,6 +544,12 @@ qemuAgentIORead(qemuAgentPtr mon)
     int ret = 0;
 
     if (avail < 1024) {
+        if (mon->bufferLength >= QEMU_AGENT_MAX_RESPONSE) {
+            virReportSystemError(ERANGE,
+                                 _("No complete agent response found in %d bytes"),
+                                 QEMU_AGENT_MAX_RESPONSE);
+            return -1;
+        }
         if (VIR_REALLOC_N(mon->buffer,
                           mon->bufferLength + 1024) < 0)
             return -1;
