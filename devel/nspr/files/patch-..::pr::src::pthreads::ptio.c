$FreeBSD$

--- ../pr/src/pthreads/ptio.c.orig	Mon Feb  2 10:41:43 2004
+++ ../pr/src/pthreads/ptio.c	Mon Feb  2 10:44:49 2004
@@ -3470,6 +3470,17 @@
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
