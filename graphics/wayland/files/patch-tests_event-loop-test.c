--- tests/event-loop-test.c.orig	2020-02-11 23:46:03 UTC
+++ tests/event-loop-test.c
@@ -168,10 +168,10 @@ TEST(event_loop_signal)
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
@@ -235,11 +235,11 @@ TEST(event_loop_timer)
 
 	source1 = wl_event_loop_add_timer(loop, timer_callback, &got_it);
 	assert(source1);
-	wl_event_source_timer_update(source1, 20);
+	assert(wl_event_source_timer_update(source1, 20) == 0);
 
 	source2 = wl_event_loop_add_timer(loop, timer_callback, &got_it);
 	assert(source2);
-	wl_event_source_timer_update(source2, 100);
+	assert(wl_event_source_timer_update(source2, 100) == 0);
 
 	/* Check that the timer marked for 20 msec from now fires within 30
 	 * msec, and that the timer marked for 100 msec is expected to fire
@@ -248,11 +248,11 @@ TEST(event_loop_timer)
 
 	wl_event_loop_dispatch(loop, 0);
 	assert(got_it == 0);
-	wl_event_loop_dispatch(loop, 30);
+	assert(wl_event_loop_dispatch(loop, 30) == 0);
 	assert(got_it == 1);
 	wl_event_loop_dispatch(loop, 0);
 	assert(got_it == 1);
-	wl_event_loop_dispatch(loop, 90);
+	assert(wl_event_loop_dispatch(loop, 90) == 0);
 	assert(got_it == 2);
 
 	wl_event_source_remove(source1);
