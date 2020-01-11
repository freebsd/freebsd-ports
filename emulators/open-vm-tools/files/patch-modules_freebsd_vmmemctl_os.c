--- modules/freebsd/vmmemctl/os.c.orig	2019-10-21 21:58:04 UTC
+++ modules/freebsd/vmmemctl/os.c
@@ -64,7 +64,11 @@
 
 typedef struct {
    /* system structures */
+#if __FreeBSD_version >= 1300067
+   struct callout callout_handle;
+#else
    struct callout_handle callout_handle;
+#endif
 
    /* termination flag */
    volatile int stop;
@@ -678,7 +682,12 @@ vmmemctl_poll(void *data) // IN
    if (!t->stop) {
       /* invoke registered handler, rearm timer */
       Balloon_QueryAndExecute();
+#if __FreeBSD_version >= 1300067
+      callout_reset(&t->callout_handle, BALLOON_POLL_PERIOD * hz, vmmemctl_poll,
+          t);
+#else
       t->callout_handle = timeout(vmmemctl_poll, t, BALLOON_POLL_PERIOD * hz);
+#endif
    }
 }
 
@@ -712,15 +721,23 @@ vmmemctl_init(void)
    }
 
    /* initialize timer state */
+#if __FreeBSD_version >= 1300067
+   callout_init(&state->timer.callout_handle, 0);
+#else
    callout_handle_init(&state->timer.callout_handle);
+#endif
 
    os_pmap_init(pmap);
    os_balloonobject_create();
 
    /* Set up and start polling */
-   callout_handle_init(&t->callout_handle);
    t->stop = FALSE;
+#if __FreeBSD_version >= 1300067
+   callout_reset(&t->callout_handle, BALLOON_POLL_PERIOD * hz, vmmemctl_poll,
+       t);
+#else
    t->callout_handle = timeout(vmmemctl_poll, t, BALLOON_POLL_PERIOD * hz);
+#endif
 
    vmmemctl_init_sysctl();
 
@@ -759,7 +776,11 @@ vmmemctl_cleanup(void)
 
    /* Stop polling */
    t->stop = TRUE;
+#if __FreeBSD_version >= 1300067
+   callout_drain(&t->callout_handle);
+#else
    untimeout(vmmemctl_poll, t, t->callout_handle);
+#endif
 
    os_balloonobject_delete();
    os_pmap_free(pmap);
