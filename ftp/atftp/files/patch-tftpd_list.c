--- tftpd_list.c.orig	2004-02-27 10:05:26.000000000 +0800
+++ tftpd_list.c	2013-10-30 13:25:57.000000000 +0800
@@ -137,23 +137,17 @@
                                              struct thread_data *data,
                                              struct client_info *client)
 {
-     struct thread_data *current = thread_data; /* head of the list */
+     struct thread_data *current;
      struct tftp_opt *tftp_options = data->tftp_options;
      struct client_info *tmp;
-     char options[MAXLEN];
-     char string[MAXLEN];
-     char *index;
-     int len;
 
      *thread = NULL;
 
-     opt_request_to_string(tftp_options, options, MAXLEN);
-     index = strstr(options, "multicast");
-     len = (int)index - (int)options;
-
      /* lock the whole list before walking it */
      pthread_mutex_lock(&thread_list_mutex);
 
+     current = thread_data; /* head of the list */ 
+
      while (current)
      {
           if (current != data)
@@ -162,9 +156,9 @@
                pthread_mutex_lock(&current->client_mutex);
                if (current->client_ready == 1)
                {
-                    opt_request_to_string(current->tftp_options, string, MAXLEN);
-                    /* must have exact same option string */
-                    if (strncmp(string, options, len) == 0)
+		    /* must have exact same mode and refer to the same file */
+		    if (opt_same_file(current->tftp_options,tftp_options) &&
+			opt_equal(&(current->tftp_options[OPT_MODE]), &(tftp_options[OPT_MODE])))
                     {
                          *thread = current;                         
                          /* insert the new client at the end. If the client is already
@@ -202,7 +196,7 @@
      return 0;
 }
 
-inline void tftpd_clientlist_ready(struct thread_data *thread)
+void tftpd_clientlist_ready(struct thread_data *thread)
 {
      pthread_mutex_lock(&thread->client_mutex);
      thread->client_ready = 1;
