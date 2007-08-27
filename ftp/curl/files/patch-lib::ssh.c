--- lib/ssh.c.old	2007-06-20 23:32:34.000000000 +0300
+++ lib/ssh.c	2007-08-27 14:10:01.000000000 +0300
@@ -70,6 +70,24 @@
 #endif
 #endif /* !WIN32 */
 
+#if defined(LIBSSH2_VERSION_NUM)
+# if LIBSSH2_VERSION_NUM >= 0x001000
+#  define HAVE_LIBSSH2_NBLOCK 1
+# else
+#  define HAVE_LIBSSH2_NBLOCK 0
+# endif
+#else /* !defined(LIBSSH2_VERSION_NUM) */
+# if defined(LIBSSH2_APINO)
+#  if LIBSSH2_APINO >= 200706012030
+#   define HAVE_LIBSSH2_NBLOCK 1
+#  else
+#   define HAVE_LIBSSH2_NBLOCK 0
+#  endif
+# else /* !defined(LIBSSH2_APINO) */
+#  define HAVE_LIBSSH2_NBLOCK 0
+# endif /* defined(LIBSSH2_APINO) */
+#endif /* defined(LIBSSH2_VERSION_NUM) */
+
 #if (defined(NETWARE) && defined(__NOVELL_LIBC__))
 #undef in_addr_t
 #define in_addr_t unsigned long
@@ -239,7 +257,7 @@
   (void)abstract;
 }
 
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
 /*
  * SSH State machine related code
  */
@@ -770,7 +788,7 @@
 
 return result;
 }
-#endif /* (LIBSSH2_APINO >= 200706012030) */
+#endif /* HAVE_LIBSSH2_NBLOCK */
 
 /*
  * SSH setup and connection
@@ -854,7 +872,7 @@
   infof(data, "SSH socket: %d\n", sock);
 #endif /* CURL_LIBSSH2_DEBUG */
 
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
   state(conn, SSH_S_STARTUP);
 
   if (data->state.used_interface == Curl_if_multi)
@@ -875,7 +893,7 @@
   (void)fingerprint; /* not used */
   (void)i; /* not used */
 
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
 
   if (libssh2_session_startup(ssh->ssh_session, sock)) {
     failf(data, "Failure establishing ssh session");
@@ -1112,7 +1130,7 @@
 
   *done = TRUE;
   return CURLE_OK;
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 }
 
 CURLcode Curl_scp_do(struct connectdata *conn, bool *done)
@@ -1134,7 +1152,7 @@
      * the destination file will be named the same name as the last directory
      * in the path.
      */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     do {
       scp->ssh_channel = libssh2_scp_send_ex(scp->ssh_session, scp->path,
                                              LIBSSH2_SFTP_S_IRUSR|
@@ -1148,7 +1166,7 @@
         return CURLE_FAILED_INIT;
       }
     } while (!scp->ssh_channel);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     scp->ssh_channel = libssh2_scp_send_ex(scp->ssh_session, scp->path,
                                            LIBSSH2_SFTP_S_IRUSR|
                                            LIBSSH2_SFTP_S_IWUSR|
@@ -1157,7 +1175,7 @@
                                            conn->data->set.infilesize, 0, 0);
     if (!scp->ssh_channel)
       return CURLE_FAILED_INIT;
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
     /* upload data */
     res = Curl_setup_transfer(conn, -1, -1, FALSE, NULL, FIRSTSOCKET, NULL);
@@ -1169,7 +1187,7 @@
      */
     curl_off_t bytecount;
     memset(&sb, 0, sizeof(struct stat));
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     do {
       scp->ssh_channel = libssh2_scp_recv(scp->ssh_session, scp->path, &sb);
       if (!scp->ssh_channel &&
@@ -1184,7 +1202,7 @@
           libssh2_session_last_error(scp->ssh_session, NULL, NULL, 0));
       }
     } while (!scp->ssh_channel);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     scp->ssh_channel = libssh2_scp_recv(scp->ssh_session, scp->path, &sb);
     if (!scp->ssh_channel) {
       if ((sb.st_mode == 0) && (sb.st_atime == 0) && (sb.st_mtime == 0) &&
@@ -1195,7 +1213,7 @@
       return libssh2_session_error_to_CURLE(
         libssh2_session_last_error(scp->ssh_session, NULL, NULL, 0));
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
     /* download data */
     bytecount = (curl_off_t) sb.st_size;
     conn->data->reqdata.maxdownload =  (curl_off_t) sb.st_size;
@@ -1217,7 +1235,7 @@
   scp->path = NULL;
 
   if (scp->ssh_channel) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     if (conn->data->set.upload) {
       while ((rc = libssh2_channel_send_eof(scp->ssh_channel)) ==
              LIBSSH2_ERROR_EAGAIN);
@@ -1235,7 +1253,7 @@
         infof(conn->data, "Channel failed to close\n");
       }
     }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     if (conn->data->set.upload &&
         libssh2_channel_send_eof(scp->ssh_channel) < 0) {
       infof(conn->data, "Failed to send libssh2 channel EOF\n");
@@ -1243,17 +1261,17 @@
     if (libssh2_channel_close(scp->ssh_channel) < 0) {
       infof(conn->data, "Failed to stop libssh2 channel subsystem\n");
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
     libssh2_channel_free(scp->ssh_channel);
   }
 
   if (scp->ssh_session) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     while (libssh2_session_disconnect(scp->ssh_session, "Shutdown") ==
            LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     libssh2_session_disconnect(scp->ssh_session, "Shutdown");
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
     libssh2_session_free(scp->ssh_session);
     scp->ssh_session = NULL;
   }
@@ -1279,7 +1297,7 @@
    * NOTE: we should not store nor rely on connection-related data to be
    * in the SessionHandle struct
    */
-#if defined(LIBSSH2CHANNEL_EAGAIN) && (LIBSSH2_APINO < 200706012030)
+#if defined(LIBSSH2CHANNEL_EAGAIN) && defined(LIBSSH2_APINO) && (LIBSSH2_APINO < 200706012030)
   nwrite = (ssize_t)
     libssh2_channel_writenb(conn->data->reqdata.proto.ssh->ssh_channel,
                             mem, len);
@@ -1287,7 +1305,7 @@
   nwrite = (ssize_t)
     libssh2_channel_write(conn->data->reqdata.proto.ssh->ssh_channel,
                           mem, len);
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
   if (nwrite == LIBSSH2_ERROR_EAGAIN) {
     return 0;
   }
@@ -1313,7 +1331,7 @@
    * in the SessionHandle struct
    */
 
-#if defined(LIBSSH2CHANNEL_EAGAIN) && (LIBSSH2_APINO < 200706012030)
+#if defined(LIBSSH2CHANNEL_EAGAIN) && defined(LIBSSH2_APINO) && (LIBSSH2_APINO < 200706012030)
   /* we prefer the non-blocking API but that didn't exist previously */
   nread = (ssize_t)
     libssh2_channel_readnb(conn->data->reqdata.proto.ssh->ssh_channel,
@@ -1358,7 +1376,7 @@
      *          If this is not done the destination file will be named the
      *          same name as the last directory in the path.
      */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     do {
       sftp->sftp_handle =
         libssh2_sftp_open(sftp->sftp_session, sftp->path,
@@ -1402,7 +1420,7 @@
         }
       }
     } while (!sftp->sftp_handle);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     sftp->sftp_handle =
       libssh2_sftp_open(sftp->sftp_session, sftp->path,
                         LIBSSH2_FXF_WRITE|LIBSSH2_FXF_CREAT|LIBSSH2_FXF_TRUNC,
@@ -1431,7 +1449,7 @@
         return sftp_libssh2_error_to_CURLE(err);
       }
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
     /* upload data */
     res = Curl_setup_transfer(conn, -1, -1, FALSE, NULL, FIRSTSOCKET, NULL);
@@ -1450,7 +1468,7 @@
       int len, totalLen, currLen;
       char *line;
 
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
       do {
         sftp->sftp_handle =
           libssh2_sftp_opendir(sftp->sftp_session, sftp->path);
@@ -1463,7 +1481,7 @@
           return sftp_libssh2_error_to_CURLE(err);
         }
       } while (!sftp->sftp_handle);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
       sftp->sftp_handle =
         libssh2_sftp_opendir(sftp->sftp_session, sftp->path);
       if (!sftp->sftp_handle) {
@@ -1472,17 +1490,17 @@
             sftp_libssh2_strerror(err));
         return sftp_libssh2_error_to_CURLE(err);
       }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
       do {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((len = libssh2_sftp_readdir(sftp->sftp_handle, filename,
                                            PATH_MAX, &attrs)) ==
                LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         len = libssh2_sftp_readdir(sftp->sftp_handle, filename,
                                    PATH_MAX, &attrs);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
         if (len > 0) {
           filename[len] = '\0';
 
@@ -1590,14 +1608,14 @@
               char linkPath[PATH_MAX + 1];
 
               snprintf(linkPath, PATH_MAX, "%s%s", sftp->path, filename);
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
               while ((len = libssh2_sftp_readlink(sftp->sftp_session, linkPath,
                                                   filename, PATH_MAX)) ==
                      LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
               len = libssh2_sftp_readlink(sftp->sftp_session, linkPath,
                                           filename, PATH_MAX);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
               line = realloc(line, totalLen + 4 + len);
               if (!line)
                 return CURLE_OUT_OF_MEMORY;
@@ -1615,11 +1633,11 @@
           break;
         }
       } while (1);
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
       while (libssh2_sftp_closedir(sftp->sftp_handle) == LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
       libssh2_sftp_closedir(sftp->sftp_handle);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       sftp->sftp_handle = NULL;
 
       /* no data to transfer */
@@ -1629,7 +1647,7 @@
       /*
        * Work on getting the specified file
        */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
       do {
         sftp->sftp_handle =
           libssh2_sftp_open(sftp->sftp_session, sftp->path, LIBSSH2_FXF_READ,
@@ -1644,7 +1662,7 @@
           return sftp_libssh2_error_to_CURLE(err);
         }
       } while (!sftp->sftp_handle);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
       sftp->sftp_handle =
         libssh2_sftp_open(sftp->sftp_session, sftp->path, LIBSSH2_FXF_READ,
                           LIBSSH2_SFTP_S_IRUSR|LIBSSH2_SFTP_S_IWUSR|
@@ -1655,14 +1673,14 @@
             sftp_libssh2_strerror(err));
         return sftp_libssh2_error_to_CURLE(err);
       }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
       while ((rc = libssh2_sftp_stat(sftp->sftp_session, sftp->path, &attrs))
              == LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
       rc = libssh2_sftp_stat(sftp->sftp_session, sftp->path, &attrs);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       if (rc) {
         /*
          * libssh2_sftp_open() didn't return an error, so maybe the server
@@ -1689,31 +1707,31 @@
                                 bytecount, FALSE, NULL, -1, NULL);
 #endif
       while (res == CURLE_OK) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         ssize_t nread;
 
         while ((nread = libssh2_sftp_read(data->reqdata.proto.ssh->sftp_handle,
                                   buf, BUFSIZE-1)) == LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         size_t nread;
         /* NOTE: most *read() functions return ssize_t but this returns size_t
           which normally is unsigned! */
         nread = libssh2_sftp_read(data->reqdata.proto.ssh->sftp_handle,
                                   buf, BUFSIZE-1);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
         if (nread > 0)
           buf[nread] = 0;
 
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         if (nread <= 0)
           break;
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         /* this check can be changed to a <= 0 when nread is changed to a
           signed variable type */
         if ((nread == 0) || (nread == (size_t)~0))
           break;
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
         bytecount += nread;
 
@@ -1756,17 +1774,17 @@
   sftp->homedir = NULL;
 
   if (sftp->sftp_handle) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     while ((ret = libssh2_sftp_close(sftp->sftp_handle)) ==
            LIBSSH2_ERROR_EAGAIN);
     if (ret < 0) {
       infof(conn->data, "Failed to close libssh2 file\n");
     }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     if (libssh2_sftp_close(sftp->sftp_handle) < 0) {
       infof(conn->data, "Failed to close libssh2 file\n");
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
   }
 
   /* Before we shut down, see if there are any post-quote commands to send: */
@@ -1776,40 +1794,40 @@
   }
 
   if (sftp->sftp_session) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     while ((ret = libssh2_sftp_shutdown(sftp->sftp_session)) ==
            LIBSSH2_ERROR_EAGAIN);
     if (ret < 0) {
       infof(conn->data, "Failed to stop libssh2 sftp subsystem\n");
     }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     if (libssh2_sftp_shutdown(sftp->sftp_session) < 0) {
       infof(conn->data, "Failed to stop libssh2 sftp subsystem\n");
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
   }
 
   if (sftp->ssh_channel) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     while ((ret = libssh2_channel_close(sftp->ssh_channel)) ==
            LIBSSH2_ERROR_EAGAIN);
     if (ret < 0) {
       infof(conn->data, "Failed to stop libssh2 channel subsystem\n");
     }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     if (libssh2_channel_close(sftp->ssh_channel) < 0) {
       infof(conn->data, "Failed to stop libssh2 channel subsystem\n");
     }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
   }
 
   if (sftp->ssh_session) {
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
     while (libssh2_session_disconnect(sftp->ssh_session, "Shutdown") ==
            LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
     libssh2_session_disconnect(sftp->ssh_session, "Shutdown");
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
     libssh2_session_free(sftp->ssh_session);
     sftp->ssh_session = NULL;
   }
@@ -1831,14 +1849,14 @@
   ssize_t nwrite;   /* libssh2_sftp_write() used to return size_t in 0.14
                        but is changed to ssize_t in 0.15! */
 
-#if defined(LIBSSH2SFTP_EAGAIN) && (LIBSSH2_APINO < 200706012030)
+#if defined(LIBSSH2SFTP_EAGAIN) && defined(LIBSSH2_APINO) && (LIBSSH2_APINO < 200706012030)
   /* we prefer the non-blocking API but that didn't exist previously */
   nwrite = (ssize_t)
     libssh2_sftp_writenb(conn->data->reqdata.proto.ssh->sftp_handle, mem, len);
 #else
   nwrite = (ssize_t)
     libssh2_sftp_write(conn->data->reqdata.proto.ssh->sftp_handle, mem, len);
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
   if (nwrite == LIBSSH2_ERROR_EAGAIN) {
     return 0;
   }
@@ -1860,7 +1878,7 @@
 
   /* libssh2_sftp_read() returns size_t !*/
 
-#if defined(LIBSSH2SFTP_EAGAIN) && (LIBSSH2_APINO < 200706012030)
+#if defined(LIBSSH2SFTP_EAGAIN) && defined(LIBSSH2_APINO) && (LIBSSH2_APINO < 200706012030)
   /* we prefer the non-blocking API but that didn't exist previously */
   nread = (ssize_t)
     libssh2_sftp_readnb(conn->data->reqdata.proto.ssh->sftp_handle, mem, len);
@@ -2061,7 +2079,7 @@
           return err;
         }
         memset(&attrs, 0, sizeof(LIBSSH2_SFTP_ATTRIBUTES));
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_stat(sftp_session,
                                         path2, &attrs)) ==
                LIBSSH2_ERROR_EAGAIN);
@@ -2073,7 +2091,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_stat(sftp_session,
                               path2, &attrs) != 0) { /* get those attributes */
           err = libssh2_sftp_last_error(sftp_session);
@@ -2083,7 +2101,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
 
         /* Now set the new attributes... */
         if (curl_strnequal(item->data, "chgrp", 5)) {
@@ -2115,7 +2133,7 @@
         }
 
         /* Now send the completed structure... */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_setstat(sftp_session, path2, &attrs)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2126,7 +2144,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_setstat(sftp_session, path2, &attrs) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
           free(path1);
@@ -2135,7 +2153,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
       else if (curl_strnequal(item->data, "ln ", 3) ||
                curl_strnequal(item->data, "symlink ", 8)) {
@@ -2151,7 +2169,7 @@
           free(path1);
           return err;
         }
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_symlink(sftp_session, path1, path2)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2162,7 +2180,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_symlink(sftp_session, path1, path2) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
           free(path1);
@@ -2171,10 +2189,10 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
       else if (curl_strnequal(item->data, "mkdir ", 6)) { /* create dir */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_mkdir(sftp_session, path1, 0744)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2183,7 +2201,7 @@
           failf(data, "mkdir command failed: %s", sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_mkdir(sftp_session, path1, 0744) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
           free(path1);
@@ -2191,7 +2209,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
       else if (curl_strnequal(item->data, "rename ", 7)) { /* rename file */
         /* first param is the source path */
@@ -2205,7 +2223,7 @@
           free(path1);
           return err;
         }
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_rename(sftp_session, path1, path2)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2215,7 +2233,7 @@
           failf(data, "rename command failed: %s", sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_rename(sftp_session,
                                 path1, path2) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
@@ -2225,10 +2243,10 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
       else if (curl_strnequal(item->data, "rmdir ", 6)) { /* delete dir */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_rmdir(sftp_session, path1)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2237,7 +2255,7 @@
           failf(data, "rmdir command failed: %s", sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_rmdir(sftp_session,
                                path1) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
@@ -2246,10 +2264,10 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
       else if (curl_strnequal(item->data, "rm ", 3)) { /* delete file */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
         while ((ret = libssh2_sftp_unlink(sftp_session, path1)) ==
                LIBSSH2_ERROR_EAGAIN);
         if (ret != 0) {
@@ -2258,7 +2276,7 @@
           failf(data, "rm command failed: %s", sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
         if (libssh2_sftp_unlink(sftp_session, path1) != 0) {
           err = libssh2_sftp_last_error(sftp_session);
           free(path1);
@@ -2266,7 +2284,7 @@
                 sftp_libssh2_strerror(err));
           return CURLE_FTP_QUOTE_ERROR;
         }
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       }
 
       if (path1)
@@ -2299,18 +2317,18 @@
 
       infof(conn->data, "Creating directory '%s'\n", sftp->path);
       /* 'mode' - parameter is preliminary - default to 0644 */
-#if (LIBSSH2_APINO >= 200706012030)
+#if HAVE_LIBSSH2_NBLOCK
       while ((rc = libssh2_sftp_mkdir(sftp->sftp_session, sftp->path,
                                LIBSSH2_SFTP_S_IRWXU |
                                LIBSSH2_SFTP_S_IRGRP | LIBSSH2_SFTP_S_IXGRP |
                                LIBSSH2_SFTP_S_IROTH | LIBSSH2_SFTP_S_IXOTH)) ==
              LIBSSH2_ERROR_EAGAIN);
-#else /* !(LIBSSH2_APINO >= 200706012030) */
+#else /* !HAVE_LIBSSH2_NBLOCK */
       rc = libssh2_sftp_mkdir(sftp->sftp_session, sftp->path,
                                LIBSSH2_SFTP_S_IRWXU |
                                LIBSSH2_SFTP_S_IRGRP | LIBSSH2_SFTP_S_IXGRP |
                                LIBSSH2_SFTP_S_IROTH | LIBSSH2_SFTP_S_IXOTH);
-#endif /* !(LIBSSH2_APINO >= 200706012030) */
+#endif /* !HAVE_LIBSSH2_NBLOCK */
       *slash_pos = '/';
       ++slash_pos;
       if (rc == -1) {
