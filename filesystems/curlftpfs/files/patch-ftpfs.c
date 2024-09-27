--- ftpfs.c.orig	2008-04-29 23:05:47 UTC
+++ ftpfs.c
@@ -257,6 +257,7 @@ static int ftpfs_getdir(const char* path, fuse_cache_d
   int err = 0;
   CURLcode curl_res;
   char* dir_path = get_fulldir_path(path);
+  char* dir_path_uri = path_to_uri(dir_path);
 
   DEBUG(1, "ftpfs_getdir: %s\n", dir_path);
   struct buffer buf;
@@ -264,7 +265,7 @@ static int ftpfs_getdir(const char* path, fuse_cache_d
 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_res = curl_easy_perform(ftpfs.connection);
   pthread_mutex_unlock(&ftpfs.lock);
@@ -278,6 +279,7 @@ static int ftpfs_getdir(const char* path, fuse_cache_d
               NULL, NULL, NULL, 0, h, filler); 
   }
 
+  free_uri(dir_path_uri);
   free(dir_path);
   buf_free(&buf);
   return op_return(err, "ftpfs_getdir");
@@ -287,6 +289,7 @@ static int ftpfs_getattr(const char* path, struct stat
   int err;
   CURLcode curl_res;
   char* dir_path = get_dir_path(path);
+  char* dir_path_uri = path_to_uri(dir_path);
 
   DEBUG(2, "ftpfs_getattr: %s dir_path=%s\n", path, dir_path);
   struct buffer buf;
@@ -294,7 +297,7 @@ static int ftpfs_getattr(const char* path, struct stat
 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_res = curl_easy_perform(ftpfs.connection);
   pthread_mutex_unlock(&ftpfs.lock);
@@ -309,6 +312,7 @@ static int ftpfs_getattr(const char* path, struct stat
   err = parse_dir((char*)buf.p, dir_path + strlen(ftpfs.host) - 1,
                   name, sbuf, NULL, 0, NULL, NULL); 
 
+  free_uri(dir_path_uri);
   free(dir_path);
   buf_free(&buf);
   if (err) return op_return(-ENOENT, "ftpfs_getattr");
@@ -329,6 +333,7 @@ static size_t ftpfs_read_chunk(const char* full_path, 
   int running_handles = 0;
   int err = 0;
   struct ftpfs_file* fh = get_ftpfs_file(fi);
+  char* full_path_uri = path_to_uri(full_path); /* TODO: optimize bu pushing up conversion to context */
 
   DEBUG(2, "ftpfs_read_chunk: %s %p %zu %lld %p %p\n",
         full_path, rbuf, size, offset, fi, fh);
@@ -355,7 +360,7 @@ static size_t ftpfs_read_chunk(const char* full_path, 
 
       cancel_previous_multi();
       
-      curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+      curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
       curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &fh->buf);
       if (offset) {
         char range[15];
@@ -444,6 +449,7 @@ static size_t ftpfs_read_chunk(const char* full_path, 
 
   pthread_mutex_unlock(&ftpfs.lock);
 
+  free_uri(full_path_uri);
   if (err) return CURLFTPFS_BAD_READ;
   return size;
 }
@@ -497,11 +503,12 @@ int write_thread_ctr = 0;
 static void *ftpfs_write_thread(void *data) {
   struct ftpfs_file *fh = data;
   char range[15];
-  
+  char* full_path_uri = path_to_uri(fh->full_path); /* TODO: optimize bu pushing up conversion to context */
+
   DEBUG(2, "enter streaming write thread #%d path=%s pos=%lld\n", ++write_thread_ctr, fh->full_path, fh->pos);
   
   
-  curl_easy_setopt_or_die(fh->write_conn, CURLOPT_URL, fh->full_path);
+  curl_easy_setopt_or_die(fh->write_conn, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(fh->write_conn, CURLOPT_UPLOAD, 1);
   curl_easy_setopt_or_die(fh->write_conn, CURLOPT_INFILESIZE, -1);
   curl_easy_setopt_or_die(fh->write_conn, CURLOPT_READFUNCTION, write_data_bg);
@@ -541,6 +548,8 @@ static void *ftpfs_write_thread(void *data) {
   
   sem_post(&fh->data_written); /* ftpfs_write may return */
 
+  free_uri(full_path_uri);
+
   return NULL;
 }
 
@@ -619,16 +628,19 @@ static void free_ftpfs_file(struct ftpfs_file *fh) {
 }
 
 static int buffer_file(struct ftpfs_file *fh) {
+  char* full_path_uri = path_to_uri(fh->full_path); /* TODO: optimize bu pushing up conversion to context */
   // If we want to write to the file, we have to load it all at once,
   // modify it in memory and then upload it as a whole as most FTP servers
   // don't support resume for uploads.
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, fh->full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &fh->buf);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
   pthread_mutex_unlock(&ftpfs.lock);
 
+  free_uri(full_path_uri);
+
   if (curl_res != 0) {
     return -EACCES;
   }
@@ -641,10 +653,11 @@ static int create_empty_file(const char * path)
   int err = 0;
 
   char *full_path = get_full_path(path);
+  char* full_path_uri = path_to_uri(full_path);
 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_INFILESIZE, 0);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_UPLOAD, 1);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_READDATA, NULL);
@@ -654,7 +667,9 @@ static int create_empty_file(const char * path)
 
   if (curl_res != 0) {
     err = -EPERM;
-  }	
+  }
+
+  free_uri(full_path_uri);
   free(full_path);
   return err;
 }
@@ -873,6 +888,7 @@ static int ftpfs_chmod(const char* path, mode_t mode) 
   
   struct curl_slist* header = NULL;
   char* full_path = get_dir_path(path);
+  char* full_path_uri = path_to_uri(full_path);
   char* filename = get_file_name(path);
   char* cmd = g_strdup_printf("SITE CHMOD %.3o %s", mode_c, filename);
   struct buffer buf;
@@ -883,7 +899,7 @@ static int ftpfs_chmod(const char* path, mode_t mode) 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_POSTQUOTE, header);
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_NOBODY, ftpfs.safe_nobody);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
@@ -894,12 +910,13 @@ static int ftpfs_chmod(const char* path, mode_t mode) 
   if (curl_res != 0) {
     err = -EPERM;
   }
-  
+
   buf_free(&buf);
   curl_slist_free_all(header);
+  free_uri(full_path_uri);
   free(full_path);
   free(filename);
-  free(cmd); 
+  free(cmd);
   return op_return(err, "ftpfs_chmod");
 }
 
@@ -910,6 +927,7 @@ static int ftpfs_chown(const char* path, uid_t uid, gi
   
   struct curl_slist* header = NULL;
   char* full_path = get_dir_path(path);
+  char* full_path_uri = path_to_uri(full_path);
   char* filename = get_file_name(path);
   char* cmd = g_strdup_printf("SITE CHUID %i %s", uid, filename);
   char* cmd2 = g_strdup_printf("SITE CHGID %i %s", gid, filename);
@@ -922,7 +940,7 @@ static int ftpfs_chown(const char* path, uid_t uid, gi
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_POSTQUOTE, header);
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_NOBODY, ftpfs.safe_nobody);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
@@ -936,6 +954,7 @@ static int ftpfs_chown(const char* path, uid_t uid, gi
   
   buf_free(&buf);
   curl_slist_free_all(header);
+  free_uri(full_path_uri);
   free(full_path);
   free(filename);
   free(cmd); 
@@ -999,6 +1018,7 @@ static int ftpfs_rmdir(const char* path) {
   int err = 0;
   struct curl_slist* header = NULL;
   char* full_path = get_dir_path(path);
+  char* full_path_uri = path_to_uri(full_path);
   char* filename = get_file_name(path);
   char* cmd = g_strdup_printf("RMD %s", filename);
   struct buffer buf;
@@ -1012,7 +1032,7 @@ static int ftpfs_rmdir(const char* path) {
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_POSTQUOTE, header);
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_NOBODY, ftpfs.safe_nobody);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
@@ -1026,6 +1046,7 @@ static int ftpfs_rmdir(const char* path) {
   
   buf_free(&buf);
   curl_slist_free_all(header);
+  free_uri(full_path_uri);
   free(full_path);
   free(filename);
   free(cmd);
@@ -1036,6 +1057,7 @@ static int ftpfs_mkdir(const char* path, mode_t mode) 
   int err = 0;
   struct curl_slist* header = NULL;
   char* full_path = get_dir_path(path);
+  char* full_path_uri = path_to_uri(full_path);
   char* filename = get_file_name(path);
   char* cmd = g_strdup_printf("MKD %s", filename);
   struct buffer buf;
@@ -1046,7 +1068,7 @@ static int ftpfs_mkdir(const char* path, mode_t mode) 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_POSTQUOTE, header);
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_NOBODY, ftpfs.safe_nobody);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
@@ -1060,6 +1082,7 @@ static int ftpfs_mkdir(const char* path, mode_t mode) 
   
   buf_free(&buf);
   curl_slist_free_all(header);
+  free_uri(full_path_uri);
   free(full_path);
   free(filename);
   free(cmd);
@@ -1074,6 +1097,7 @@ static int ftpfs_unlink(const char* path) {
   int err = 0;
   struct curl_slist* header = NULL;
   char* full_path = get_dir_path(path);
+  char* full_path_uri = path_to_uri(full_path);
   char* filename = get_file_name(path);
   char* cmd = g_strdup_printf("DELE %s", filename);
   struct buffer buf;
@@ -1084,7 +1108,7 @@ static int ftpfs_unlink(const char* path) {
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_POSTQUOTE, header);
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, full_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_NOBODY, ftpfs.safe_nobody);
   CURLcode curl_res = curl_easy_perform(ftpfs.connection);
@@ -1098,6 +1122,7 @@ static int ftpfs_unlink(const char* path) {
   
   buf_free(&buf);
   curl_slist_free_all(header);
+  free_uri(full_path_uri);
   free(full_path);
   free(filename);
   free(cmd);
@@ -1299,6 +1324,7 @@ static int ftpfs_readlink(const char *path, char *link
   int err;
   CURLcode curl_res;
   char* dir_path = get_dir_path(path);
+  char* dir_path_uri = path_to_uri(dir_path);
 
   DEBUG(2, "dir_path: %s %s\n", path, dir_path);
   struct buffer buf;
@@ -1306,7 +1332,7 @@ static int ftpfs_readlink(const char *path, char *link
 
   pthread_mutex_lock(&ftpfs.lock);
   cancel_previous_multi();
-  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path);
+  curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_URL, dir_path_uri);
   curl_easy_setopt_or_die(ftpfs.connection, CURLOPT_WRITEDATA, &buf);
   curl_res = curl_easy_perform(ftpfs.connection);
   pthread_mutex_unlock(&ftpfs.lock);
@@ -1321,6 +1347,7 @@ static int ftpfs_readlink(const char *path, char *link
   err = parse_dir((char*)buf.p, dir_path + strlen(ftpfs.host) - 1,
                   name, NULL, linkbuf, size, NULL, NULL); 
 
+  free_uri(dir_path_uri);
   free(dir_path);
   buf_free(&buf);
   if (err) return op_return(-ENOENT, "ftpfs_readlink");
