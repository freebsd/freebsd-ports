--- tftpd_list.c.orig	2010-10-05 13:11:12.000000000 +0800
+++ tftpd_list.c	2010-10-05 13:18:09.000000000 +0800
@@ -149,7 +149,7 @@
 
      opt_request_to_string(tftp_options, options, MAXLEN);
      index = strstr(options, "multicast");
-     len = (int)index - (int)options;
+     len = strlen(options) - strlen(index);
 
      /* lock the whole list before walking it */
      pthread_mutex_lock(&thread_list_mutex);
