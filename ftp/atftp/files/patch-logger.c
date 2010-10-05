--- logger.c.orig	2004-02-27 10:05:26.000000000 +0800
+++ logger.c	2010-10-05 12:34:41.000000000 +0800
@@ -3,7 +3,7 @@
  * logger.c
  *    functions for logging messages.
  *
- * $Id: logger.c,v 1.12 2004/02/27 02:05:26 jp Exp $
+ * $Id: logger.c 1769 2010-09-29 08:46:26Z kevlo $
  *
  * Copyright (c) 2000 Jean-Pierre Lefebvre <helix@step.polymtl.ca>
  *                and Remi Lefebvre <remi@debian.org>
@@ -27,6 +27,7 @@
 #include <time.h>
 #include <unistd.h>
 #include <netdb.h>
+#include <pthread.h>
 #include "logger.h"
 
 #define MAXLEN 128
@@ -56,7 +57,15 @@
           log_ident = "unset";
 
      if (filename)
+     {
           log_filename = strdup(filename);
+          if (!strcmp(filename, "-"))
+          {
+               log_fd = STDOUT_FILENO;
+               log_fp = fdopen(log_fd, "a");
+               return;
+          }
+     }
      else
      {
           openlog(log_ident, LOG_PID, LOG_DAEMON);
@@ -105,15 +114,17 @@
           
           if (log_fp)
           {
-               fprintf(log_fp, "%s %s %s[%d.%d]: %s\n", time_buf, hostname,
-                       log_ident, getpid(), pthread_self(), message);
+               fprintf(log_fp, "%s %s %s[%ld.%ld]: %s\n", time_buf, hostname,
+                       log_ident, (long)getpid(), (long)pthread_self(), 
+                       message);
                fflush(log_fp);
           }
           else if (log_syslog_is_open)
                syslog(severity, "%s", message);
           else
-               fprintf(stderr, "%s %s %s[%d.%d]: %s\n", time_buf, hostname,
-                       log_ident, getpid(), pthread_self(), message);
+               fprintf(stderr, "%s %s %s[%ld.%ld]: %s\n", time_buf, hostname,
+                       log_ident, (long)getpid(), (long)pthread_self(), 
+                       message);
      }
      va_end(args);
 }
