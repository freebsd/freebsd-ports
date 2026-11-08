--- daemon/quic_stream.c.orig	2026-08-05 09:40:54 UTC
+++ daemon/quic_stream.c
@@ -8,6 +8,11 @@
 #include "session2.h"
 #include <stdint.h>
 #include "quic_stream.h"
+#include <errno.h>
+
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif

 /* forward declaration */
 static int send_stream(struct pl_quic_stream_sess_data *stream,
