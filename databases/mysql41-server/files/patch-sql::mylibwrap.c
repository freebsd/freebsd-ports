--- sql/mylibwrap.c.orig	Thu Jan  1 01:00:00 1970
+++ sql/mylibwrap.c		Sun Sep 19 15:37:22 2004
@@ -0,0 +1,20 @@
+#include <tcpd.h>
+#include "mylibwrap.h"
+
+void
+my_fromhost(struct request_info *req)
+{
+	fromhost(req);
+}
+
+int
+my_hosts_access(struct request_info *req)
+{
+	return hosts_access(req);
+}
+
+char *
+my_eval_client(struct request_info *req)
+{
+	return eval_client(req);
+}
