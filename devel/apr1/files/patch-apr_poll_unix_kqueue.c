# upstram PR: https://bz.apache.org/bugzilla/show_bug.cgi?id=59914
# FreeBSD PR: 211430
========================================================================
--- apr-1.5.2/poll/unix/kqueue.c.orig	2015-03-20 01:34:07 UTC
+++ apr-1.5.2/poll/unix/kqueue.c
@@ -25,21 +25,40 @@
 
 #ifdef HAVE_KQUEUE
 
-static apr_int16_t get_kqueue_revent(apr_int16_t event, apr_int16_t flags)
+static apr_int16_t get_kqueue_revent(apr_int16_t event, apr_int16_t flags,
+                                     int fflags, intptr_t data)
 {
     apr_int16_t rv = 0;
 
-    if (event == EVFILT_READ)
-        rv |= APR_POLLIN;
-    else if (event == EVFILT_WRITE)
-        rv |= APR_POLLOUT;
-    if (flags & EV_EOF)
-        rv |= APR_POLLHUP;
-    /* APR_POLLPRI, APR_POLLERR, and APR_POLLNVAL are not handled by this
-     * implementation.
+    /* APR_POLLPRI and APR_POLLNVAL are not handled by this implementation.
      * TODO: See if EV_ERROR + certain system errors in the returned data field
      * should map to APR_POLLNVAL.
      */
+    if (event == EVFILT_READ) {
+	if (data > 0 || fflags == 0)
+	    rv |= APR_POLLIN;
+	else
+	    rv |= APR_POLLERR;
+        /*
+	 * Don't return POLLHUP if connect fails.  Apparently Linux
+         * does not, and this is expected by serf in order for IPv6 to
+	 * IPv4 or multihomed host fallback to work.
+         *
+	 * ETIMEDOUT is ambiguous here since we don't know if a
+	 * connection was established.  We don't want to return
+	 * POLLHUP here if the connection attempt timed out, but
+	 * we do if the connection was successful but later dropped.
+	 * For now, favor the latter.
+	 */
+	if ((flags & EV_EOF) != 0 && fflags != ECONNREFUSED &&
+	    fflags != ENETUNREACH && fflags != EHOSTUNREACH)
+	    rv |= APR_POLLHUP;
+    } else if (event == EVFILT_WRITE) {
+	if (data > 0 || fflags == 0)
+	    rv |= APR_POLLOUT;
+	else
+	    rv |= APR_POLLERR;
+    }
     return rv;
 }
 
@@ -290,7 +309,9 @@ static apr_status_t impl_pollset_poll(ap
                 pollset->p->result_set[j] = fd;
                 pollset->p->result_set[j].rtnevents =
                         get_kqueue_revent(pollset->p->ke_set[i].filter,
-                                          pollset->p->ke_set[i].flags);
+                                          pollset->p->ke_set[i].flags,
+                                          pollset->p->ke_set[i].fflags,
+                                          pollset->p->ke_set[i].data);
                 j++;
             }
         }
@@ -471,7 +492,9 @@ static apr_status_t impl_pollcb_poll(apr
             apr_pollfd_t *pollfd = (apr_pollfd_t *)(pollcb->pollset.ke[i].udata);
             
             pollfd->rtnevents = get_kqueue_revent(pollcb->pollset.ke[i].filter,
-                                                  pollcb->pollset.ke[i].flags);
+                                                  pollcb->pollset.ke[i].flags,
+                                                  pollcb->pollset.ke[i].fflags,
+                                                  pollcb->pollset.ke[i].data);
             
             rv = func(baton, pollfd);
             
