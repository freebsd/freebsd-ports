--- src/gap/ap_reactor.cpp.orig
+++ src/gap/ap_reactor.cpp
@@ -98,17 +98,27 @@
 #ifndef WIN32
   FXint n;
   if (timeout>=0) {
+#ifdef _GNU_SOURCE
     struct timespec ts;
     ts.tv_sec  = timeout / 1000000000;
     ts.tv_nsec = timeout % 1000000000;
+#endif
     do {
+#ifdef _GNU_SOURCE
       n = ppoll(pfds,nfds,&ts,NULL);
+#else
+      n = poll(pfds,nfds,-1);
+#endif
       }
     while(n==-1 && errno==EINTR);
     }
   else {
     do {
+#ifdef _GNU_SOURCE
       n = ppoll(pfds,nfds,NULL,NULL);
+#else
+      n = poll(pfds,nfds,0);
+#endif
       }
     while(n==-1 && errno==EINTR);
     }    
