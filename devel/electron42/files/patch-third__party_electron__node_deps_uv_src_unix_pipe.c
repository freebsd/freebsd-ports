--- third_party/electron_node/deps/uv/src/unix/pipe.c.orig	2025-06-24 07:41:14 UTC
+++ third_party/electron_node/deps/uv/src/unix/pipe.c
@@ -209,9 +209,13 @@ int uv_pipe_open(uv_pipe_t* handle, uv_file fd) {
   if (mode == -1)
     return UV__ERR(errno); /* according to docs, must be EBADF */
 
+  /* If ioctl(FIONBIO) reports ENOTTY, try fcntl(F_GETFL) + fcntl(F_SETFL).
+   * Workaround for e.g. kqueue fds not supporting ioctls.
+   */
   err = uv__nonblock(fd, 1);
-  if (err)
-    return err;
+  if (err == UV_ENOTTY)
+    if (uv__nonblock == uv__nonblock_ioctl)
+      err = uv__nonblock_fcntl(fd, 1);
 
 #if defined(__APPLE__)
   err = uv__stream_try_select((uv_stream_t*) handle, &fd);
