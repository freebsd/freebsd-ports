--- jartool.c.orig	2025-02-09 11:28:36 UTC
+++ jartool.c
@@ -790,6 +790,7 @@ int read_entries (int fd)
 		   progname, jarfile);
 	  return 1;
 	}
+      ze->filename[len] = '\0';
       len = UNPACK_UB4(header, CEN_EFLEN);
       len += UNPACK_UB4(header, CEN_COMLEN);
       if (lseek (fd, len, SEEK_CUR) == -1)
@@ -1257,7 +1258,7 @@ int add_file_to_jar(int jfd, int ffd, const char *fnam
       exit_on_error("write");
 
   /* write the file name to the zip file */
-  if (1 == write(jfd, fname, file_name_length))
+  if (-1 == write(jfd, fname, file_name_length))
     exit_on_error("write");
 
   if(verbose){
@@ -1273,15 +1274,18 @@ int add_file_to_jar(int jfd, int ffd, const char *fnam
     compress_file(ffd, jfd, ze, existing);
   } else {
     /* If we are not writing the last entry, make space for it. */
-    if (existing && existing->next_entry)
+    if (existing) 
       {
-	if (ze->usize > existing->usize)
+	if (existing->next_entry) 
 	  {
-	    if (shift_down (jfd, existing->next_entry->offset,
-			    ze->usize - existing->usize, existing->next_entry))
+	    if (ze->usize > existing->usize) 
 	      {
-		fprintf (stderr, "%s: %s\n", progname, strerror (errno));
-		return 1;
+		if (shift_down (jfd, existing->next_entry->offset,
+				ze->usize - existing->usize, existing->next_entry))
+		  {
+		    fprintf (stderr, "%s: %s\n", progname, strerror (errno));
+		    return 1;
+		  }
 	      }
 	  }
       }
@@ -1730,33 +1734,46 @@ int extract_jar(int fd, const char **files, int file_n
       struct stat sbuf;
       int depth = 0;
 
-      tmp_buff = malloc(sizeof(char) * strlen((const char *)filename));
+      if(*filename == '/'){
+	fprintf(stderr, "Absolute path names are not allowed.\n");
+	exit(EXIT_FAILURE);
+      }
 
+      tmp_buff = malloc(strlen((const char *)filename));
+
+      if(tmp_buff == NULL) {
+	fprintf(stderr, "Out of memory.\n");
+	exit(EXIT_FAILURE);
+      }
+
       for(;;){
         const ub1 *idx = (const unsigned char *)strchr((const char *)start, '/');
 
         if(idx == NULL)
           break;
         else if(idx == start){
+	  tmp_buff[idx - filename] = '/';
           start++;
           continue;
         }
-        start = idx + 1;
 
-        strncpy(tmp_buff, (const char *)filename, (idx - filename));
-        tmp_buff[(idx - filename)] = '\0';
+	memcpy(tmp_buff + (start - filename), (const char *)start, (idx - start));
+	tmp_buff[idx - filename] = '\0';
 
 #ifdef DEBUG    
         printf("checking the existance of %s\n", tmp_buff);
 #endif
-	if(strcmp(tmp_buff, "..") == 0){
+	if(idx - start == 2 && memcmp(start, "..", 2) == 0){
 	  --depth;
 	  if (depth < 0){
 	    fprintf(stderr, "Traversal to parent directories during unpacking!\n");
 	    exit(EXIT_FAILURE);
 	  }
-	} else if (strcmp(tmp_buff, ".") != 0)
+	} else if (idx - start != 1 || *start != '.')
 	  ++depth;
+
+        start = idx + 1;
+
         if(stat(tmp_buff, &sbuf) < 0){
           if(errno != ENOENT)
             exit_on_error("stat");
@@ -1765,6 +1782,7 @@ int extract_jar(int fd, const char **files, int file_n
 #ifdef DEBUG    
           printf("Directory exists\n");
 #endif
+	  tmp_buff[idx - filename] = '/';
           continue;
         }else {
           fprintf(stderr, "Hmmm.. %s exists but isn't a directory!\n",
@@ -1781,10 +1799,11 @@ int extract_jar(int fd, const char **files, int file_n
         if(verbose && handle)
           printf("%10s: %s/\n", "created", tmp_buff);
 
+	tmp_buff[idx - filename] = '/';
       }
 
       /* only a directory */
-      if(strlen((const char *)start) == 0)
+      if(*start == '\0')
         dir = TRUE;
 
 #ifdef DEBUG    
@@ -1792,7 +1811,7 @@ int extract_jar(int fd, const char **files, int file_n
 #endif
 
       /* If the entry was just a directory, don't write to file, etc */
-      if(strlen((const char *)start) == 0)
+      if(*start == '\0')
         f_fd = -1;
 
       free(tmp_buff);
@@ -1876,7 +1895,8 @@ int extract_jar(int fd, const char **files, int file_n
       exit(EXIT_FAILURE);
     }
 
-    close(f_fd);
+    if (f_fd != -1)
+      close(f_fd);
 
     if(verbose && dir == FALSE && handle)
       printf("%10s: %s\n",
