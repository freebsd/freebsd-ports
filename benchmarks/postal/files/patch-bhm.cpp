--- bhm.cpp.orig	2012-01-14 12:09:31 UTC
+++ bhm.cpp
@@ -3,27 +3,25 @@
 #endif
 
 #include "bhmusers.h"
-#include <errno.h>
-#include <ctype.h>
+#include <cerrno>
+#include <cctype>
 #include <unistd.h>
 #include <sys/wait.h>
-#include <signal.h>
-#include <stdio.h>
+#include <csignal>
+#include <cstdio>
+#include <cstdlib>
 #include <sys/poll.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#ifndef __FreeBSD__
 #include <netinet/ip.h>
+#endif
 
 #include "postal.h"
 #include "logit.h"
 #include "results.h"
 #include "basictcp.h"
-#ifdef USE_GNUTLS
-#include <errno.h>
-#include <gcrypt.h>
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
-#endif
 
 int processes = 0;
 int *thread_status;
@@ -47,7 +45,7 @@ void usage(CPCCHAR msg = NULL)
 
 int maxMsgSize = 10240;
 results res;
-Logit *log;
+Logit *bhm_log;
 
 int exitCount = 0;
 
@@ -261,7 +259,7 @@ int readCommand(base_tcp &t, char *buf, 
 
 void do_work(thread_data *td)
 {
-  base_tcp t(td->fd, log, td->debug, &res
+  base_tcp t(td->fd, bhm_log, td->debug, &res
 #ifdef USE_SSL
     , td->ssl
 #endif
@@ -408,7 +406,7 @@ int main(int argc, char **argv)
 #endif
     "\n");
 
-  log = new Logit("bhm.log", allLog, false, 0);
+  bhm_log = new Logit("bhm.log", allLog, false, 0);
   Logit *debug = NULL;
 
   if(debugName)
