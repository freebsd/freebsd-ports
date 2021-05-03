Index: io/iom_wait.c
===================================================================
RCS file: /cvs/libowfat/io/iom_wait.c,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- io/iom_wait.c	11 Apr 2018 14:12:50 -0000	1.2
+++ io/iom_wait.c	21 Feb 2019 12:43:06 -0000	1.3
@@ -65,7 +65,8 @@
 #elif defined(HAVE_KQUEUE)
       struct kevent kev[SLOTS];
       struct timespec ts = { .tv_sec=timeout/1000, .tv_nsec=(timeout%1000)*1000000 };
-      int r=kevent(c->ctx, 0, 0, &kev, freeslots, &ts);
+      int r=kevent(c->ctx, 0, 0, kev, freeslots, &ts);
+      int i;
       if (r<=0) {
 	/* we ran into a timeout, so let someone else take over */
 	if (__sync_val_compare_and_swap(&c->working,1,0)==-2) return -2;
@@ -82,7 +83,7 @@
 	        (kev[i].filter == EVFILT_WRITE ? IOM_WRITE : 0);
 	if (i+1==r) {
 	  /* return last event instead of enqueueing it */
-	  *s=kev.ident;
+	  *s=kev[i].ident;
 	  *revents=e;
 	} else {
 	  c->q[c->h].fd=kev[i].ident;
