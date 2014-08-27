--- src/gap/ap_utils.cpp.orig
+++ src/gap/ap_utils.cpp
@@ -247,17 +247,27 @@
     nfds=2;
     }
   if (timeout) {
+#ifdef _GNU_SOURCE
     struct timespec ts;
     ts.tv_sec  = (timeout / 1000000000);
     ts.tv_nsec = (timeout % 1000000000);
+#endif
     do {
+#ifdef _GNU_SOURCE
       n=ppoll(fds,nfds,&ts,NULL);
+#else
+      n=poll(fds,nfds,-1);
+#endif
       }
     while(n==-1 && (errno==EAGAIN || errno==EINTR));
     }
   else {
     do {
+#ifdef _GNU_SOURCE
       n=ppoll(fds,nfds,NULL,NULL);
+#else
+      n=poll(fds,nfds,0);
+#endif
       }
     while(n==-1 && (errno==EAGAIN || errno==EINTR));
     }
