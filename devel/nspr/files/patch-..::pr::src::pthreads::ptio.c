--- ../pr/src/pthreads/ptio.c	2009-05-09 23:07:02.000000000 -0400
+++ ../pr/src/pthreads/ptio.c	2009-11-04 15:24:47.000000000 -0500
@@ -1168,7 +1168,7 @@
         osfd = socket(AF_INET6, SOCK_STREAM, 0);
         if (osfd != -1) {
             int on;
-            int optlen = sizeof(on);
+            socklen_t optlen = sizeof(on);
             if (getsockopt(osfd, IPPROTO_IPV6, IPV6_V6ONLY,
                     &on, &optlen) == 0) {
                 _pr_ipv6_v6only_on_by_default = on;
@@ -3495,6 +3495,17 @@
                     &on, sizeof(on));
         }
 #endif
+#if (defined(_PR_INET6_PROBE) || defined(_PR_INET6)) && \
+	defined(__FreeBSD__) && defined(IPV6_V6ONLY)
+		if (domain == PR_AF_INET6) {
+			int opt = 0;
+			if (setsockopt(osfd, IPPROTO_IPV6, IPV6_V6ONLY,
+			    &opt, sizeof(opt))) {
+				close(osfd);
+				return NULL;
+			}
+		}
+#endif  
         fd = pt_SetMethods(osfd, ftype, PR_FALSE, PR_FALSE);
         if (fd == NULL) close(osfd);
     }
@@ -3758,7 +3769,7 @@
      * We use these variables to figure out how much time has
      * elapsed and how much of the timeout still remains.
      */
-    PRIntervalTime start, elapsed, remaining;
+    PRIntervalTime start = 0, elapsed, remaining;
 
     if (pt_TestAbort()) return -1;
 
@@ -4927,6 +4938,7 @@
 
     if (timeout == PR_INTERVAL_NO_TIMEOUT) {
         tvp = NULL;
+        start = 0; /* Not needed, but shuts down a warning */
     } else {
         tv.tv_sec = (PRInt32)PR_IntervalToSeconds(timeout);
         tv.tv_usec = (PRInt32)PR_IntervalToMicroseconds(
