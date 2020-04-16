--- src/unix/udp.c.orig	2020-04-15 16:31:21 UTC
+++ src/unix/udp.c
@@ -32,8 +32,6 @@
 #endif
 #include <sys/un.h>
 
-#define UV__UDP_DGRAM_MAXSIZE (64 * 1024)
-
 #if defined(IPV6_JOIN_GROUP) && !defined(IPV6_ADD_MEMBERSHIP)
 # define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
 #endif
@@ -51,37 +49,7 @@ static int uv__udp_maybe_deferred_bind(uv_udp_t* handl
                                        int domain,
                                        unsigned int flags);
 
-#if HAVE_MMSG
 
-#define UV__MMSG_MAXWIDTH 20
-
-static int uv__udp_recvmmsg(uv_udp_t* handle, uv_buf_t* buf);
-static void uv__udp_sendmmsg(uv_udp_t* handle);
-
-static int uv__recvmmsg_avail;
-static int uv__sendmmsg_avail;
-static uv_once_t once = UV_ONCE_INIT;
-
-static void uv__udp_mmsg_init(void) {
-  int ret;
-  int s;
-  s = uv__socket(AF_INET, SOCK_DGRAM, 0);
-  if (s < 0)
-    return;
-  ret = uv__sendmmsg(s, NULL, 0, 0);
-  if (ret == 0 || errno != ENOSYS) {
-    uv__sendmmsg_avail = 1;
-    uv__recvmmsg_avail = 1;
-  } else {
-    ret = uv__recvmmsg(s, NULL, 0, 0, NULL);
-    if (ret == 0 || errno != ENOSYS)
-      uv__recvmmsg_avail = 1;
-  }
-  uv__close(s);
-}
-
-#endif
-
 void uv__udp_close(uv_udp_t* handle) {
   uv__io_close(handle->loop, &handle->io_watcher);
   uv__handle_stop(handle);
@@ -180,62 +148,7 @@ static void uv__udp_io(uv_loop_t* loop, uv__io_t* w, u
   }
 }
 
-#if HAVE_MMSG
-static int uv__udp_recvmmsg(uv_udp_t* handle, uv_buf_t* buf) {
-  struct sockaddr_in6 peers[UV__MMSG_MAXWIDTH];
-  struct iovec iov[UV__MMSG_MAXWIDTH];
-  struct uv__mmsghdr msgs[UV__MMSG_MAXWIDTH];
-  ssize_t nread;
-  uv_buf_t chunk_buf;
-  size_t chunks;
-  int flags;
-  size_t k;
 
-  /* prepare structures for recvmmsg */
-  chunks = buf->len / UV__UDP_DGRAM_MAXSIZE;
-  if (chunks > ARRAY_SIZE(iov))
-    chunks = ARRAY_SIZE(iov);
-  for (k = 0; k < chunks; ++k) {
-    iov[k].iov_base = buf->base + k * UV__UDP_DGRAM_MAXSIZE;
-    iov[k].iov_len = UV__UDP_DGRAM_MAXSIZE;
-    msgs[k].msg_hdr.msg_iov = iov + k;
-    msgs[k].msg_hdr.msg_iovlen = 1;
-    msgs[k].msg_hdr.msg_name = peers + k;
-    msgs[k].msg_hdr.msg_namelen = sizeof(peers[0]);
-  }
-
-  do
-    nread = uv__recvmmsg(handle->io_watcher.fd, msgs, chunks, 0, NULL);
-  while (nread == -1 && errno == EINTR);
-
-  if (nread < 1) {
-    if (nread == 0 || errno == EAGAIN || errno == EWOULDBLOCK)
-      handle->recv_cb(handle, 0, buf, NULL, 0);
-    else
-      handle->recv_cb(handle, UV__ERR(errno), buf, NULL, 0);
-  } else {
-    /* pass each chunk to the application */
-    for (k = 0; k < (size_t) nread && handle->recv_cb != NULL; k++) {
-      flags = UV_UDP_MMSG_CHUNK;
-      if (msgs[k].msg_hdr.msg_flags & MSG_TRUNC)
-        flags |= UV_UDP_PARTIAL;
-
-      chunk_buf = uv_buf_init(iov[k].iov_base, iov[k].iov_len);
-      handle->recv_cb(handle,
-                      msgs[k].msg_len,
-                      &chunk_buf,
-                      msgs[k].msg_hdr.msg_name,
-                      flags);
-    }
-
-    /* one last callback so the original buffer is freed */
-    if (handle->recv_cb != NULL)
-      handle->recv_cb(handle, 0, buf, NULL, 0);
-  }
-  return nread;
-}
-#endif
-
 static void uv__udp_recvmsg(uv_udp_t* handle) {
   struct sockaddr_storage peer;
   struct msghdr h;
@@ -254,27 +167,13 @@ static void uv__udp_recvmsg(uv_udp_t* handle) {
 
   do {
     buf = uv_buf_init(NULL, 0);
-    handle->alloc_cb((uv_handle_t*) handle, UV__UDP_DGRAM_MAXSIZE, &buf);
+    handle->alloc_cb((uv_handle_t*) handle, 64 * 1024, &buf);
     if (buf.base == NULL || buf.len == 0) {
       handle->recv_cb(handle, UV_ENOBUFS, &buf, NULL, 0);
       return;
     }
     assert(buf.base != NULL);
 
-#if HAVE_MMSG
-    uv_once(&once, uv__udp_mmsg_init);
-    if (uv__recvmmsg_avail) {
-      /* Returned space for more than 1 datagram, use it to receive
-       * multiple datagrams. */
-      if (buf.len >= 2 * UV__UDP_DGRAM_MAXSIZE) {
-        nread = uv__udp_recvmmsg(handle, &buf);
-        if (nread > 0)
-          count -= nread;
-        continue;
-      }
-    }
-#endif
-
     memset(&h, 0, sizeof(h));
     memset(&peer, 0, sizeof(peer));
     h.msg_name = &peer;
@@ -300,120 +199,21 @@ static void uv__udp_recvmsg(uv_udp_t* handle) {
 
       handle->recv_cb(handle, nread, &buf, (const struct sockaddr*) &peer, flags);
     }
-    count--;
   }
   /* recv_cb callback may decide to pause or close the handle */
   while (nread != -1
-      && count > 0
+      && count-- > 0
       && handle->io_watcher.fd != -1
       && handle->recv_cb != NULL);
 }
 
-#if HAVE_MMSG
-static void uv__udp_sendmmsg(uv_udp_t* handle) {
-  uv_udp_send_t* req;
-  struct uv__mmsghdr h[UV__MMSG_MAXWIDTH];
-  struct uv__mmsghdr *p;
-  QUEUE* q;
-  ssize_t npkts;
-  size_t pkts;
-  size_t i;
 
-  if (QUEUE_EMPTY(&handle->write_queue))
-    return;
-
-write_queue_drain:
-  for (pkts = 0, q = QUEUE_HEAD(&handle->write_queue);
-       pkts < UV__MMSG_MAXWIDTH && q != &handle->write_queue;
-       ++pkts, q = QUEUE_HEAD(q)) {
-    assert(q != NULL);
-    req = QUEUE_DATA(q, uv_udp_send_t, queue);
-    assert(req != NULL);
-
-    p = &h[pkts];
-    memset(p, 0, sizeof(*p));
-    if (req->addr.ss_family == AF_UNSPEC) {
-      p->msg_hdr.msg_name = NULL;
-      p->msg_hdr.msg_namelen = 0;
-    } else {
-      p->msg_hdr.msg_name = &req->addr;
-      if (req->addr.ss_family == AF_INET6)
-        p->msg_hdr.msg_namelen = sizeof(struct sockaddr_in6);
-      else if (req->addr.ss_family == AF_INET)
-        p->msg_hdr.msg_namelen = sizeof(struct sockaddr_in);
-      else if (req->addr.ss_family == AF_UNIX)
-        p->msg_hdr.msg_namelen = sizeof(struct sockaddr_un);
-      else {
-        assert(0 && "unsupported address family");
-        abort();
-      }
-    }
-    h[pkts].msg_hdr.msg_iov = (struct iovec*) req->bufs;
-    h[pkts].msg_hdr.msg_iovlen = req->nbufs;
-  }
-
-  do
-    npkts = uv__sendmmsg(handle->io_watcher.fd, h, pkts, 0);
-  while (npkts == -1 && errno == EINTR);
-
-  if (npkts < 1) {
-    if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ENOBUFS)
-      return;
-    for (i = 0, q = QUEUE_HEAD(&handle->write_queue);
-         i < pkts && q != &handle->write_queue;
-         ++i, q = QUEUE_HEAD(q)) {
-      assert(q != NULL);
-      req = QUEUE_DATA(q, uv_udp_send_t, queue);
-      assert(req != NULL);
-
-      req->status = UV__ERR(errno);
-      QUEUE_REMOVE(&req->queue);
-      QUEUE_INSERT_TAIL(&handle->write_completed_queue, &req->queue);
-    }
-    uv__io_feed(handle->loop, &handle->io_watcher);
-    return;
-  }
-
-  for (i = 0, q = QUEUE_HEAD(&handle->write_queue);
-       i < pkts && q != &handle->write_queue;
-       ++i, q = QUEUE_HEAD(&handle->write_queue)) {
-    assert(q != NULL);
-    req = QUEUE_DATA(q, uv_udp_send_t, queue);
-    assert(req != NULL);
-
-    req->status = req->bufs[0].len;
-
-    /* Sending a datagram is an atomic operation: either all data
-     * is written or nothing is (and EMSGSIZE is raised). That is
-     * why we don't handle partial writes. Just pop the request
-     * off the write queue and onto the completed queue, done.
-     */
-    QUEUE_REMOVE(&req->queue);
-    QUEUE_INSERT_TAIL(&handle->write_completed_queue, &req->queue);
-  }
-
-  /* couldn't batch everything, continue sending (jump to avoid stack growth) */
-  if (!QUEUE_EMPTY(&handle->write_queue))
-    goto write_queue_drain;
-  uv__io_feed(handle->loop, &handle->io_watcher);
-  return;
-}
-#endif
-
 static void uv__udp_sendmsg(uv_udp_t* handle) {
   uv_udp_send_t* req;
-  struct msghdr h;
   QUEUE* q;
+  struct msghdr h;
   ssize_t size;
 
-#if HAVE_MMSG
-  uv_once(&once, uv__udp_mmsg_init);
-  if (uv__sendmmsg_avail) {
-    uv__udp_sendmmsg(handle);
-    return;
-  }
-#endif
-
   while (!QUEUE_EMPTY(&handle->write_queue)) {
     q = QUEUE_HEAD(&handle->write_queue);
     assert(q != NULL);
@@ -463,6 +263,7 @@ static void uv__udp_sendmsg(uv_udp_t* handle) {
   }
 }
 
+
 /* On the BSDs, SO_REUSEPORT implies SO_REUSEADDR but with some additional
  * refinements for programs that use multicast.
  *
@@ -1333,3 +1134,4 @@ int uv__udp_recv_stop(uv_udp_t* handle) {
 
   return 0;
 }
+
