
$FreeBSD$

--- erts/emulator/drivers/common/efile_drv.c.orig
+++ erts/emulator/drivers/common/efile_drv.c
@@ -311,6 +311,18 @@
     unsigned        flags;    /* Original flags from FILE_OPEN. */
     void          (*invoke)(void *);
     struct t_data  *d;
+    /*
+     * If an operation against a compressed file is being executed
+     * by an async thread, ensure the stop callback doesn't close
+     * the fd (gzFile) while the async thread doesn't finish using
+     * the fd (gzFile) - otherwise it accesses a dangling pointer.
+     * The following comp_op_* variables are used to coordinate the
+     * driver stop callback with the ongoing async operation.
+     */
+    int             comp_op_in_progress;
+    volatile int    comp_op_done;
+    erts_mtx_t      comp_op_mtx;
+    erts_cnd_t      comp_op_cnd;
     void          (*free)(void *);
     struct t_data  *cq_head;  /* Queue of incoming commands */
     struct t_data  *cq_tail;  /* -""- */
@@ -426,6 +438,9 @@
     struct t_data *next;
     int            command;
     int            level;
+    int volatile  *comp_op_done;
+    erts_mtx_t    *comp_op_mtx;
+    erts_cnd_t    *comp_op_cnd;
     void         (*invoke)(void *);
     void         (*free)(void *);
     int            again;
@@ -714,6 +729,14 @@
     return d;
 }
 
+static void signal_comp_op_done(struct t_data *d) {
+    if (d->comp_op_done != NULL) {
+        erts_mtx_lock(d->comp_op_mtx);
+        *(d->comp_op_done) = 1;
+        erts_cnd_signal(d->comp_op_cnd);
+        erts_mtx_unlock(d->comp_op_mtx);
+    }
+}
 
 /*********************************************************************
  * Driver entry point -> init
@@ -757,6 +780,8 @@
     desc->key = (unsigned int) (UWord) port;
     desc->flags = 0;
     desc->invoke = NULL;
+    desc->comp_op_in_progress = 0;
+    desc->comp_op_done = 0;
     desc->d = NULL;
     desc->free = NULL;
     desc->cq_head = NULL;
@@ -800,6 +825,7 @@
     DTRACE_INVOKE_SETUP(FILE_CLOSE);
     d->again = 0;
     do_close(d->flags, d->fd);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_CLOSE);
 }
 
@@ -814,9 +840,20 @@
     TRACE_C('p');
 
     if (desc->fd != FILE_FD_INVALID) {
+	if (desc->comp_op_in_progress) {
+	    erts_mtx_lock(&desc->comp_op_mtx);
+	    while (!desc->comp_op_done) {
+		erts_cnd_wait(&desc->comp_op_cnd, &desc->comp_op_mtx);
+	    }
+	    erts_mtx_unlock(&desc->comp_op_mtx);
+	}
 	do_close(desc->flags, desc->fd);
 	desc->fd = FILE_FD_INVALID;
 	desc->flags = 0;
+	if (sys_info.async_threads > 0 && (desc->flags & EFILE_COMPRESSED)) {
+	    erts_cnd_destroy(&desc->comp_op_cnd);
+	    erts_mtx_destroy(&desc->comp_op_mtx);
+	}
     }
     if (desc->read_binp) {
 	driver_free_binary(desc->read_binp);
@@ -1032,6 +1069,7 @@
 {
     DTRACE_INVOKE_SETUP_BY_NAME(FILE_MKDIR);
     invoke_name(data, efile_mkdir);
+    signal_comp_op_done((struct t_data *) data);
     DTRACE_INVOKE_RETURN(FILE_MKDIR);
 }
 
@@ -1039,6 +1077,7 @@
 {
     DTRACE_INVOKE_SETUP_BY_NAME(FILE_RMDIR);
     invoke_name(data, efile_rmdir);
+    signal_comp_op_done((struct t_data *) data);
     DTRACE_INVOKE_RETURN(FILE_RMDIR);
 }
 
@@ -1046,6 +1085,7 @@
 {
     DTRACE_INVOKE_SETUP_BY_NAME(FILE_DELETE);
     invoke_name(data, efile_delete_file);
+    signal_comp_op_done((struct t_data *) data);
     DTRACE_INVOKE_RETURN(FILE_DELETE);
 }
 
@@ -1053,6 +1093,7 @@
 {
     DTRACE_INVOKE_SETUP_BY_NAME(FILE_CHDIR);
     invoke_name(data, efile_chdir);
+    signal_comp_op_done((struct t_data *) data);
     DTRACE_INVOKE_RETURN(FILE_CHDIR);
 }
 
@@ -1064,6 +1105,7 @@
 
     d->again = 0;
     d->result_ok = efile_fdatasync(&d->errInfo, fd);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_FDATASYNC);
 }
 
@@ -1075,6 +1117,7 @@
 
     d->again = 0;
     d->result_ok = efile_fsync(&d->errInfo, fd);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_FSYNC);
 }
 
@@ -1086,6 +1129,7 @@
 
     d->again = 0;
     d->result_ok = efile_truncate_file(&d->errInfo, &fd, d->flags);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_TRUNCATE);
 }
 
@@ -1129,6 +1173,7 @@
     } else {
 	d->again = 0;
     }
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_READ);
 }
 
@@ -1238,6 +1283,7 @@
 	    break;
 	}
     } while (local_loop);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_READ_LINE);
 }
 
@@ -1298,6 +1344,7 @@
  done:
     d->again = 0;
  chop_done:
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_READ_FILE);
 }
 
@@ -1363,6 +1410,7 @@
     }					
     d->again = 0;
  done:
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_PREADV);
 }
 
@@ -1434,6 +1482,7 @@
  done:
     d->result_ok = !0;
     d->again = 0;
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_IPREAD);
 }
 
@@ -1531,6 +1580,7 @@
 	TRACE_F(("w%lu", (unsigned long)size));
 
     }
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_WRITE);
 }
 
@@ -1550,6 +1600,7 @@
     d->again = 0;
     d->result_ok = efile_getdcwd(&d->errInfo,d->drive, d->b+1,
 				 RESBUFSIZE-1);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_PWD);
 }
 
@@ -1564,6 +1615,7 @@
 				  RESBUFSIZE-1);
     if (d->result_ok != 0)
 	FILENAME_COPY((char *) d->b + 1, resbuf+1);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_READLINK);
 }
 
@@ -1578,6 +1630,7 @@
 				  RESBUFSIZE-1);
     if (d->result_ok != 0)
 	FILENAME_COPY((char *) d->b + 1, resbuf+1);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_ALTNAME);
 }
 
@@ -1670,6 +1723,7 @@
 	}
     }
  done:
+    signal_comp_op_done(d);
     EF_FREE(iov); /* Free our copy of the vector, nothing to restore */
     DTRACE_INVOKE_RETURN(FILE_PWRITEV);
 }
@@ -1695,6 +1749,7 @@
     DTRACE3(efile_drv_int_entry, d->sched_i1, d->sched_i2,
             d->command == FILE_LSTAT ? FILE_LSTAT : FILE_FSTAT);
     gcc_optimizer_hack++;
+    signal_comp_op_done(d);
 }
 
 static void invoke_link(void *data)
@@ -1707,6 +1762,7 @@
     d->again = 0;
     new_name = name+FILENAME_BYTELEN(name)+FILENAME_CHARSIZE;
     d->result_ok = efile_link(&d->errInfo, name, new_name);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_LINK);
 }
 
@@ -1720,6 +1776,7 @@
     d->again = 0;
     new_name = name+FILENAME_BYTELEN(name)+FILENAME_CHARSIZE;
     d->result_ok = efile_symlink(&d->errInfo, name, new_name);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_SYMLINK);
 }
 
@@ -1733,6 +1790,7 @@
     d->again = 0;
     new_name = name+FILENAME_BYTELEN(name)+FILENAME_CHARSIZE;
     d->result_ok = efile_rename(&d->errInfo, name, new_name);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_RENAME);
 }
 
@@ -1743,6 +1801,7 @@
 
     d->again = 0;
     d->result_ok = efile_write_info(&d->errInfo, &d->info, d->b);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_WRITE_INFO);
 }
 
@@ -1775,6 +1834,7 @@
 			    &d->c.lseek.location);
     }
     d->result_ok = status;
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_LSEEK);
 }
 
@@ -1822,6 +1882,7 @@
     } while(res);
 
     d->result_ok = (d->errInfo.posix_errno == 0);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_READDIR);
 }
 
@@ -1876,6 +1937,7 @@
 
     d->again = 0;
     d->result_ok = efile_fadvise(&d->errInfo, fd, offset, length, advise);
+    signal_comp_op_done(d);
     DTRACE_INVOKE_RETURN(FILE_FADVISE);
 }
 
@@ -1906,6 +1968,7 @@
     } else {
 	d->result_ok = -1;
     }
+    signal_comp_op_done(d);
 }
 
 static void free_sendfile(void *data) {
@@ -2023,6 +2086,21 @@
 	return;
     TRACE_F(("x%i", (int) d->command));
     d->again = sys_info.async_threads == 0;
+
+    if ((desc->flags & EFILE_COMPRESSED) && (sys_info.async_threads > 0) &&
+        (desc->fd != FILE_FD_INVALID)) {
+
+	desc->comp_op_in_progress = 1;
+	desc->comp_op_done = 0;
+	d->comp_op_done = &desc->comp_op_done;
+	d->comp_op_mtx = &desc->comp_op_mtx;
+	d->comp_op_cnd = &desc->comp_op_cnd;
+    } else {
+	d->comp_op_done = NULL;
+	d->comp_op_mtx = NULL;
+	d->comp_op_cnd = NULL;
+    }
+
     DRIVER_ASYNC(d->level, desc, d->invoke, void_ptr=d, d->free);
 }
 
@@ -2247,6 +2325,8 @@
 	return;
     }
 
+    desc->comp_op_in_progress = 0;
+
     switch (d->command)
     {
     case FILE_READ:
@@ -2375,6 +2455,10 @@
 	} else {
 	    desc->fd = d->fd;
 	    desc->flags = d->flags;
+	    if (sys_info.async_threads > 0 && (desc->flags & EFILE_COMPRESSED)) {
+		erts_mtx_init(&desc->comp_op_mtx, "efile_drv comp op mutex");
+		erts_cnd_init(&desc->comp_op_cnd);
+	    }
 	    reply_Uint(desc, d->fd);
 	}
 	free_data(data);
