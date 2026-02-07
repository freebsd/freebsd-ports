--- bhm.cpp.orig	2016-06-30 09:04:24 UTC
+++ bhm.cpp
@@ -50,7 +50,7 @@
 
 int maxMsgSize = 10240;
 results res;
-Logit *log;
+Logit *bhm_log;
 
 int exitCount = 0;
 
@@ -264,7 +264,7 @@
 
 void do_work(thread_data *td)
 {
-  base_tcp t(td->fd, log, td->debug, &res
+  base_tcp t(td->fd, bhm_log, td->debug, &res
 #ifdef USE_SSL
     , td->ssl
 #endif
@@ -414,7 +414,7 @@
 #endif
     "\n");
 
-  log = new Logit("bhm.log", allLog, false, 0);
+  bhm_log = new Logit("bhm.log", allLog, false, 0);
   Logit *debug = NULL;
 
   if(debugName)
@@ -425,7 +425,7 @@
   in.sin_family = AF_INET;
   in.sin_port = htons(port);
   memcpy(&in.sin_addr, &sin_addr, sizeof(sin_addr));
-  if(listen_fd == -1 || bind(listen_fd, (sockaddr *)&in, sizeof(in))
+  if(listen_fd == -1 || ::bind(listen_fd, (sockaddr *)&in, sizeof(in))
    || listen(listen_fd, 10))
   {
     fprintf(stderr, "Can't bind to port.\n");
