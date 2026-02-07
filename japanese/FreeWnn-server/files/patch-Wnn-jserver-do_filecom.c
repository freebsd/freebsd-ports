Index: Wnn/jserver/do_filecom.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/do_filecom.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/jserver/do_filecom.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jserver/do_filecom.c	2 Jan 2010 11:51:24 -0000	1.2
@@ -868,82 +868,96 @@ js_file_write (void)
 void
 js_file_receive (void)
 {
-  int env_id, fid;
-  struct wnn_file_uniq fq;
-  int mode = 1;
-  int i;
-  int error = 0;
+	int env_id, fid;
+	struct wnn_file_uniq fq;
+	int mode = 1;
+	int i;
+	int error = 0;
+
+	env_id = get4_cur();         /* env_id */
+	fid = get4_cur();
+	if (find_fid_in_env(env_id, fid) == -1) {
+		fprintf(stderr, "find_fid_in_env failed\n");
+
+		/* valid */
+		/* dummy */
+		puts_cur ("!");
+		putc_purge();
+		
+		error = 1;
+	} else {
+		fprintf(stderr, "find_fid_in_env success: %s\n",
+			files[fid].name);
+		puts_cur(files[fid].name);
+		putc_purge();
+
+	}
+
+	fprintf(stderr, "get4\n");
+       	if (get4_cur() == -1) {
+		/* Ack */
+		return;
+	}
+	fprintf(stderr, "get4: end\n");
+
+	fprintf(stderr, "get4 x 3 start\n");
+
+	fq.time = get4_cur();
+	fq.dev = get4_cur();
+	fq.inode = get4_cur();
+
+	fprintf(stderr, "get4 x 3 end\n");
+
+	for (i = 0; i < WNN_HOSTLEN; i++) {
+		fq.createhost[i] = getc_cur();
+	}
+
+	if (error || files[fid].ref_count == -1) {
+		wnn_errorno = WNN_FID_ERROR;
+		error_ret ();
+		putc_purge ();
+		return;
+	}
+
+	if (fq.time != 0) {
+		/* Old File Exist */
+		mode = must_write_file (&files[fid], &fq);
+	}
+
+	if (mode == -1) {
+		wnn_errorno = WNN_FID_ERROR;
+		error_ret ();
+		putc_purge ();
+		return;
+	} else if (mode == 0) {
+		/* need not saving */
+		put4_cur(0);
+		putc_purge();
+		return;
+	}
+
+	put4_cur (mode);
+	putc_purge ();
+
+	if (get4_cur () == -1)
+		return;
+
+	if (rcv_file (&files[fid], mode) == -1) {
+		/*      wnn_errorno=WNN_FILE_WRITE_ERROR; */
+		error_ret();
+		putc_purge();
+		return;
+	}
+
+	if (mode == 1 || mode == 2) {
+		clear_dirty_bit (&files[fid]);
+	}
 
-  env_id = get4_cur ();         /* env_id */
-  fid = get4_cur ();
-   /**/ if (find_fid_in_env (env_id, fid) == -1)
-    {                           /* valid */
-      puts_cur ("!");
-      putc_purge ();            /* dummy */
-      error = 1;
-    }
-  else
-    {
-      puts_cur (files[fid].name);
-      putc_purge ();
-    }
-  if (get4_cur () == -1)
-    return;                     /* Ack */
-
-  fq.time = get4_cur ();
-  fq.dev = get4_cur ();
-  fq.inode = get4_cur ();
-  for (i = 0; i < WNN_HOSTLEN; i++)
-    {
-      fq.createhost[i] = getc_cur ();
-    }
-  if (error || files[fid].ref_count == -1)
-    {
-      wnn_errorno = WNN_FID_ERROR;
-      error_ret ();
-      putc_purge ();
-      return;
-    }
-  if (fq.time != 0)
-    {                           /* Old File Exist */
-      mode = must_write_file (&files[fid], &fq);
-    }
-
-  if (mode == -1)
-    {
-      wnn_errorno = WNN_FID_ERROR;
-      error_ret ();
-      putc_purge ();
-      return;
-    }
-  else if (mode == 0)
-    {                           /* need not saving */
-      put4_cur (0);
-      putc_purge ();
-      return;
-    }
-  put4_cur (mode);
-  putc_purge ();
-
-  if (get4_cur () == -1)
-    return;
-
-   /**/ if (rcv_file (&files[fid], mode) == -1)
-    {
-/*      wnn_errorno=WNN_FILE_WRITE_ERROR; */ error_ret ();
-      putc_purge ();
-      return;
-    }
-  if (mode == 1 || mode == 2)
-    {
-      clear_dirty_bit (&files[fid]);
-    }
-
-  put4_cur (0);
+	put4_cur (0);
 /*
- put4_cur(fid);
+  put4_cur(fid);
 */
-  putc_purge ();
+	putc_purge();
 }
 
 
@@ -994,18 +1008,18 @@ del_fid_from_env (int env_id, int fid)
 int
 find_fid_in_env (int env_id, int fid)
 {
-  register int i;
-  register int *file = env[env_id]->file;
-  for (i = 0; i < WNN_MAX_FILE_OF_AN_ENV; i++)
-    {
-      if ((file)[i] == -1)
-        continue;
-      if ((file)[i] == fid)
-        {
-          return i;
-        }
-    }
-  return -1;
+	int i;
+	int *file = env[env_id]->file;
+
+	for (i = 0; i < WNN_MAX_FILE_OF_AN_ENV; i++) {
+		if ((file)[i] == -1)
+			continue;
+		if ((file)[i] == fid) {
+			return i;
+		}
+	}
+
+	return -1;
 }
 
 static int
