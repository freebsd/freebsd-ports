--- include/uv.h.orig	2020-04-15 16:31:21 UTC
+++ include/uv.h
@@ -1,4 +1,4 @@
-/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
+/* COPYRIGHT JOYENT, INC. AND OTHER NODE CONTRIBUTORS. ALL RIGHTS RESERVED.
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -607,8 +607,7 @@ enum uv_udp_flags {
    */
   UV_UDP_REUSEADDR = 4,
   /*
-   * Indicates that the message was received by recvmmsg, so the buffer provided
-   * must not be freed by the recv_cb callback.
+   * Unused. Here for API/ABI compatibility.
    */
   UV_UDP_MMSG_CHUNK = 8
 };
@@ -1802,3 +1801,4 @@ UV_EXTERN void uv_loop_set_data(uv_loop_t*, void* data
 }
 #endif
 #endif /* UV_H */
+
