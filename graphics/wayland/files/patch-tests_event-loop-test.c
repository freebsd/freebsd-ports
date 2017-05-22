--- tests/event-loop-test.c.orig	2016-10-22 16:23:10 UTC
+++ tests/event-loop-test.c
@@ -167,10 +167,10 @@ TEST(event_loop_signal)
 					  signal_callback, &got_it);
 	assert(source);
 
-	wl_event_loop_dispatch(loop, 0);
+	assert(wl_event_loop_dispatch(loop, 0) == 0);
 	assert(!got_it);
-	kill(getpid(), SIGUSR1);
-	wl_event_loop_dispatch(loop, 0);
+	assert(kill(getpid(), SIGUSR1) == 0);
+	assert(wl_event_loop_dispatch(loop, 0) == 0);
 	assert(got_it == 1);
 
 	wl_event_source_remove(source);
@@ -234,12 +234,20 @@ TEST(event_loop_timer)
 
 	source = wl_event_loop_add_timer(loop, timer_callback, &got_it);
 	assert(source);
-	wl_event_source_timer_update(source, 10);
-	wl_event_loop_dispatch(loop, 0);
+	assert(wl_event_source_timer_update(source, 10) == 0);
+	assert(wl_event_loop_dispatch(loop, 0) == 0);
 	assert(!got_it);
-	wl_event_loop_dispatch(loop, 20);
+	/* FreeBSD has a bug where it converts ms_timeout to ticks; it always adds 1 to the tick count.
+	* Consequently, we need to grossly overcompensate here.
+	* See: http://unix.derkeiler.com/Mailing-Lists/FreeBSD/hackers/2012-07/msg00319.html */
+	assert(wl_event_loop_dispatch(loop, 50) == 0);
 	assert(got_it == 1);
 
+	/* Check it doesn't fire again. */
+	got_it = 0;
+	assert(wl_event_loop_dispatch(loop, 20) == 0);
+	assert(!got_it);
+
 	wl_event_source_remove(source);
 	wl_event_loop_destroy(loop);
 }
