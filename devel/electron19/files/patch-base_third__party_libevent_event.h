--- base/third_party/libevent/event.h.orig	2022-05-25 04:00:43 UTC
+++ base/third_party/libevent/event.h
@@ -1,3 +1,6 @@
+#if defined(USE_SYSTEM_LIBEVENT)
+#include <event.h>
+#else
 /*
  * Copyright (c) 2000-2007 Niels Provos <provos@citi.umich.edu>
  * All rights reserved.
@@ -1210,3 +1213,4 @@ int evtag_unmarshal_timeval(struct evbuffer *evbuf, ev
 #endif
 
 #endif /* _EVENT_H_ */
+#endif
