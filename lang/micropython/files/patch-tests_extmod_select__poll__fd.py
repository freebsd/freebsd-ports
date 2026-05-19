--- tests/extmod/select_poll_fd.py.orig	2026-05-19 02:06:38 UTC
+++ tests/extmod/select_poll_fd.py
@@ -42,7 +42,12 @@ try:
     poller.register(fd)
 try:
     poller.poll()
-    assert False
+    # poll() did not raise EINVAL.  On FreeBSD, poll(2) checks nfds against
+    # kern.maxfilesperproc (which can be hundreds of thousands) rather than
+    # RLIMIT_NOFILE, so triggering EINVAL with a fixed count of 6000 is not
+    # possible.  Registering enough fds to exceed the actual limit would be
+    # impractically slow.  Skip this sub-test.
+    print("SKIP: fd limit > 6000, triggering poll() EINVAL not practical")
 except OSError as er:
     print(er.errno == errno.EINVAL)
 
