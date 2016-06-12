--- ./jdk/src/solaris/native/java/net/bsd_close.c	Fri Apr 15 03:53:39 2016 +0100
+++ ./jdk/src/solaris/native/java/net/bsd_close.c	Sun May 01 21:26:40 2016 -0700
@@ -345,6 +345,76 @@
  * signal other than our wakeup signal.
  */
 int NET_Timeout(int s, long timeout) {
+/*
+ * On MacOS X, poll(2) is not working correctly, so a select(2) based
+ * implementation is preferred.  See
+ *
+ * http://bugs.sun.com/bugdatabase/view_bug.do?bug_id=7131399
+ *
+ * However, on FreeBSD, the select(2) based implementation can cause
+ * crashes under load and poll(2) is preferred.  See
+ *
+ * http://docs.freebsd.org/cgi/getmsg.cgi?fetch=215525+0+current/freebsd-java
+ *
+ * Other *BSD will use poll(2) for now, but please adjust as appropriate.
+ */
+#ifndef __APPLE__
+    long prevtime = 0, newtime;
+    struct timeval t;
+    fdEntry_t *fdEntry = getFdEntry(s);
+
+    /*
+     * Check that fd hasn't been closed.
+     */
+    if (fdEntry == NULL) {
+        errno = EBADF;
+        return -1;
+    }
+
+    /*
+     * Pick up current time as may need to adjust timeout
+     */
+    if (timeout > 0) {
+        gettimeofday(&t, NULL);
+        prevtime = t.tv_sec * 1000  +  t.tv_usec / 1000;
+    }
+
+    for(;;) {
+        struct pollfd pfd;
+        int rv;
+        threadEntry_t self;
+
+        /*
+         * Poll the fd. If interrupted by our wakeup signal
+         * errno will be set to EBADF.
+         */
+        pfd.fd = s;
+        pfd.events = POLLIN | POLLERR;
+
+        startOp(fdEntry, &self);
+        rv = poll(&pfd, 1, timeout);
+        endOp(fdEntry, &self);
+
+        /*
+         * If interrupted then adjust timeout. If timeout
+         * has expired return 0 (indicating timeout expired).
+         */
+        if (rv < 0 && errno == EINTR) {
+            if (timeout > 0) {
+                gettimeofday(&t, NULL);
+                newtime = t.tv_sec * 1000  +  t.tv_usec / 1000;
+                timeout -= newtime - prevtime;
+                if (timeout <= 0) {
+                    return 0;
+                }
+                prevtime = newtime;
+            }
+        } else {
+            return rv;
+        }
+
+    }
+#else
     long prevtime = 0, newtime;
     struct timeval t, *tp = &t;
     fd_set fds;
@@ -431,4 +501,5 @@
         }
 
     }
+#endif
 }
