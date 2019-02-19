$OpenBSD: patch-rec_channel_cc,v 1.1.1.1 2018/12/29 14:29:08 sthen Exp $

Index: rec_channel.cc
--- rec_channel.cc.orig	2019-01-31 19:43:44 UTC
+++ rec_channel.cc
@@ -54,6 +54,10 @@ int RecursorControlChannel::listen(const string& fname
   if(bind(d_fd, (sockaddr*)&d_local,sizeof(d_local))<0) 
     throw PDNSException("Unable to bind to controlsocket '"+fname+"': "+stringerror());
 
+  int bufsz = 60*1024;
+  setsockopt(d_fd, SOL_SOCKET, SO_SNDBUF, &bufsz, sizeof(bufsz));
+  bufsz = 64*1024;
+  setsockopt(d_fd, SOL_SOCKET, SO_RCVBUF, &bufsz, sizeof(bufsz));
   return d_fd;
 }
 
@@ -99,6 +103,10 @@ void RecursorControlChannel::connect(const string& pat
 	unlink(d_local.sun_path);
       throw PDNSException("Unable to connect to remote '"+string(remote.sun_path)+"': "+stringerror());
     }
+    int bufsz = 60*1024;
+    setsockopt(d_fd, SOL_SOCKET, SO_SNDBUF, &bufsz, sizeof(bufsz));
+    bufsz = 64*1024;
+    setsockopt(d_fd, SOL_SOCKET, SO_RCVBUF, &bufsz, sizeof(bufsz));
 
   } catch (...) {
     close(d_fd);
