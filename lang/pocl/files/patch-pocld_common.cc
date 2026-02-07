--- pocld/common.cc.orig	2025-06-02 18:01:19 UTC
+++ pocld/common.cc
@@ -35,6 +35,10 @@
 #include <sys/uio.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 void replyID(Reply *rep, ReplyMessageType t, uint32_t id) {
   rep->rep.message_type = t;
   rep->rep.failed = 0;
