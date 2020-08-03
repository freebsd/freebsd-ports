--- hfile_libcurl.c.orig	2019-12-19 09:54:30 UTC
+++ hfile_libcurl.c
@@ -74,6 +74,10 @@ typedef struct {
     unsigned int size;
 } hdrlist;
 
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
+
 typedef struct {
     hdrlist fixed;                   // List of headers supplied at hopen()
     hdrlist extra;                   // List of headers from callback
@@ -218,6 +222,8 @@ static int easy_errno(CURL *easy, CURLcode err)
         return EEXIST;
 
     default:
+        hts_log_error("Libcurl reported error %d (%s)", (int) err,
+                      curl_easy_strerror(err));
         return EIO;
     }
 }
@@ -238,6 +244,8 @@ static int multi_errno(CURLMcode errm)
         return ENOMEM;
 
     default:
+        hts_log_error("Libcurl reported error %d (%s)", (int) errm,
+                      curl_multi_strerror(errm));
         return EIO;
     }
 }
@@ -797,9 +805,13 @@ static ssize_t libcurl_read(hFILE *fpv, void *bufferv,
         fp->buffer.ptr.rd = buffer;
         fp->buffer.len = nbytes;
         fp->paused = 0;
-        err = curl_easy_pause(fp->easy, CURLPAUSE_CONT);
-        if (err != CURLE_OK) { errno = easy_errno(fp->easy, err); return -1; }
-
+	if (! fp->finished) {
+            err = curl_easy_pause(fp->easy, CURLPAUSE_CONT);
+            if (err != CURLE_OK) {
+		errno = easy_errno(fp->easy, err);
+		return -1;
+	    }
+	}
         while (! fp->paused && ! fp->finished) {
             if (wait_perform(fp) < 0) return -1;
         }
@@ -1003,12 +1015,6 @@ static int restart_from_position(hFILE_libcurl *fp, of
     }
     temp_fp.nrunning = ++fp->nrunning;
 
-    err = curl_easy_pause(temp_fp.easy, CURLPAUSE_CONT);
-    if (err != CURLE_OK) {
-        save_errno = easy_errno(temp_fp.easy, err);
-        goto error_remove;
-    }
-
     while (! temp_fp.paused && ! temp_fp.finished)
         if (wait_perform(&temp_fp) < 0) {
             save_errno = errno;
@@ -1084,8 +1090,10 @@ static int libcurl_close(hFILE *fpv)
     fp->buffer.len = 0;
     fp->closing = 1;
     fp->paused = 0;
-    err = curl_easy_pause(fp->easy, CURLPAUSE_CONT);
-    if (err != CURLE_OK) save_errno = easy_errno(fp->easy, err);
+    if (! fp->finished) {
+        err = curl_easy_pause(fp->easy, CURLPAUSE_CONT);
+        if (err != CURLE_OK) save_errno = easy_errno(fp->easy, err);
+    }
 
     while (save_errno == 0 && ! fp->paused && ! fp->finished)
         if (wait_perform(fp) < 0) save_errno = errno;
