Temporarily revert https://gitlab.freedesktop.org/wayland/wayland/commit/60a8d29ad852
until https://github.com/jiixyj/epoll-shim/issues/15 is fixed

--- src/event-loop.c.orig	2020-02-11 23:46:03 UTC
+++ src/event-loop.c
@@ -23,7 +23,6 @@
  * SOFTWARE.
  */
 
-#include <assert.h>
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
@@ -46,27 +45,6 @@
 
 /** \cond INTERNAL */
 
-#define TIMER_REMOVED -2
-
-struct wl_event_loop;
-struct wl_event_source_interface;
-struct wl_event_source_timer;
-
-struct wl_event_source {
-	struct wl_event_source_interface *interface;
-	struct wl_event_loop *loop;
-	struct wl_list link;
-	void *data;
-	int fd;
-};
-
-struct wl_timer_heap {
-	struct wl_event_source base;
-	/* pointers to the user-visible event sources */
-	struct wl_event_source_timer **data;
-	int space, active, count;
-};
-
 struct wl_event_loop {
 	int epoll_fd;
 	struct wl_list check_list;
@@ -74,8 +52,6 @@ struct wl_event_loop {
 	struct wl_list destroy_list;
 
 	struct wl_signal destroy_signal;
-
-	struct wl_timer_heap timers;
 };
 
 struct wl_event_source_interface {
@@ -83,6 +59,13 @@ struct wl_event_source_interface {
 			struct epoll_event *ep);
 };
 
+struct wl_event_source {
+	struct wl_event_source_interface *interface;
+	struct wl_event_loop *loop;
+	struct wl_list link;
+	void *data;
+	int fd;
+};
 
 struct wl_event_source_fd {
 	struct wl_event_source base;
@@ -232,319 +215,31 @@ wl_event_source_fd_update(struct wl_event_source *sour
 struct wl_event_source_timer {
 	struct wl_event_source base;
 	wl_event_loop_timer_func_t func;
-	struct wl_event_source_timer *next_due;
-	struct timespec deadline;
-	int heap_idx;
 };
 
-static int
-noop_dispatch(struct wl_event_source *source,
-	      struct epoll_event *ep) {
-	return 0;
-}
+/** \endcond */
 
-struct wl_event_source_interface timer_heap_source_interface = {
-	noop_dispatch,
-};
-
-static bool
-time_lt(struct timespec ta, struct timespec tb)
-{
-	if (ta.tv_sec != tb.tv_sec) {
-		return ta.tv_sec < tb.tv_sec;
-	}
-	return ta.tv_nsec < tb.tv_nsec;
-}
-
 static int
-set_timer(int timerfd, struct timespec deadline) {
-	struct itimerspec its;
-
-	its.it_interval.tv_sec = 0;
-	its.it_interval.tv_nsec = 0;
-	its.it_value = deadline;
-	return timerfd_settime(timerfd, TFD_TIMER_ABSTIME, &its, NULL);
-}
-
-static int
-clear_timer(int timerfd)
-{
-	struct itimerspec its;
-
-	its.it_interval.tv_sec = 0;
-	its.it_interval.tv_nsec = 0;
-	its.it_value.tv_sec = 0;
-	its.it_value.tv_nsec = 0;
-	return timerfd_settime(timerfd, 0, &its, NULL);
-}
-
-static void
-wl_timer_heap_init(struct wl_timer_heap *timers, struct wl_event_loop *loop)
-{
-	timers->base.fd = -1;
-	timers->base.data = NULL;
-	wl_list_init(&timers->base.link);
-	timers->base.interface = &timer_heap_source_interface;
-	timers->base.loop = loop;
-
-	loop->timers.data = NULL;
-	loop->timers.active = 0;
-	loop->timers.space = 0;
-	loop->timers.count = 0;
-}
-
-static void
-wl_timer_heap_release(struct wl_timer_heap *timers)
-{
-	if (timers->base.fd != -1) {
-		close(timers->base.fd);
-	}
-	free(timers->data);
-}
-
-static int
-wl_timer_heap_ensure_timerfd(struct wl_timer_heap *timers)
-{
-	struct epoll_event ep;
-	int timer_fd;
-
-	if (timers->base.fd != -1)
-		return 0;
-
-	memset(&ep, 0, sizeof ep);
-	ep.events = EPOLLIN;
-	ep.data.ptr = timers;
-
-	timer_fd = timerfd_create(CLOCK_MONOTONIC,
-				  TFD_CLOEXEC | TFD_NONBLOCK);
-	if (timer_fd < 0)
-		return -1;
-
-	if (epoll_ctl(timers->base.loop->epoll_fd,
-		      EPOLL_CTL_ADD, timer_fd, &ep) < 0) {
-		close(timer_fd);
-		return -1;
-	}
-
-	timers->base.fd = timer_fd;
-	return 0;
-}
-
-static int
-wl_timer_heap_reserve(struct wl_timer_heap *timers)
-{
-	struct wl_event_source_timer **n;
-	int new_space;
-
-	if (timers->count + 1 > timers->space) {
-		new_space = timers->space >= 8 ? timers->space * 2 : 8;
-		n = realloc(timers->data, (size_t)new_space * sizeof(*n));
-		if (!n) {
-			wl_log("Allocation failure when expanding timer list");
-			return -1;
-		}
-		timers->data = n;
-		timers->space = new_space;
-	}
-
-	timers->count++;
-	return 0;
-}
-
-static void
-wl_timer_heap_unreserve(struct wl_timer_heap *timers)
-{
-	struct wl_event_source_timer **n;
-
-	timers->count--;
-
-	if (timers->space >= 16 && timers->space >= 4 * timers->count) {
-		n = realloc(timers->data, (size_t)timers->space / 2 * sizeof(*n));
-		if (!n) {
-			wl_log("Reallocation failure when shrinking timer list");
-			return;
-		}
-		timers->data = n;
-		timers->space = timers->space / 2;
-	}
-}
-
-static int
-heap_set(struct wl_event_source_timer **data,
-	 struct wl_event_source_timer *a,
-	 int idx)
-{
-	int tmp;
-
-	tmp = a->heap_idx;
-	a->heap_idx = idx;
-	data[a->heap_idx] = a;
-
-	return tmp;
-}
-
-static void
-heap_sift_down(struct wl_event_source_timer **data,
-	       int num_active,
-	       struct wl_event_source_timer *source)
-{
-	struct wl_event_source_timer *child, *other_child;
-	int cursor_idx;
-	struct timespec key;
-
-	cursor_idx = source->heap_idx;
-	key = source->deadline;
-	while (1) {
-		int lchild_idx = cursor_idx * 2 + 1;
-
-		if (lchild_idx >= num_active) {
-			break;
-		}
-
-		child = data[lchild_idx];
-		if (lchild_idx + 1 < num_active) {
-			other_child = data[lchild_idx + 1];
-			if (time_lt(other_child->deadline, child->deadline))
-				child = other_child;
-		}
-
-		if (time_lt(child->deadline, key))
-			cursor_idx = heap_set(data, child, cursor_idx);
-		else
-			break;
-	}
-
-	heap_set(data, source, cursor_idx);
-}
-
-static void
-heap_sift_up(struct wl_event_source_timer **data,
-	     struct wl_event_source_timer *source)
-{
-	int cursor_idx;
-	struct timespec key;
-
-	cursor_idx = source->heap_idx;
-	key = source->deadline;
-	while (cursor_idx > 0) {
-		struct wl_event_source_timer *parent =
-			data[(cursor_idx - 1) / 2];
-
-		if (time_lt(key, parent->deadline))
-			cursor_idx = heap_set(data, parent, cursor_idx);
-		else
-			break;
-	}
-	heap_set(data, source, cursor_idx);
-}
-
-/* requires timer be armed */
-static void
-wl_timer_heap_disarm(struct wl_timer_heap *timers,
-		     struct wl_event_source_timer *source)
-{
-	struct wl_event_source_timer *last_end_evt;
-	int old_source_idx;
-
-	assert(source->heap_idx >= 0);
-
-	old_source_idx = source->heap_idx;
-	source->heap_idx = -1;
-	source->deadline.tv_sec = 0;
-	source->deadline.tv_nsec = 0;
-
-	last_end_evt = timers->data[timers->active - 1];
-	timers->data[timers->active - 1] = NULL;
-	timers->active--;
-
-	if (old_source_idx == timers->active)
-		return;
-
-	timers->data[old_source_idx] = last_end_evt;
-	last_end_evt->heap_idx = old_source_idx;
-
-	/* Move the displaced (active) element to its proper place.
-	 * Only one of sift-down and sift-up will have any effect */
-	heap_sift_down(timers->data, timers->active, last_end_evt);
-	heap_sift_up(timers->data, last_end_evt);
-}
-
-/* requires timer be disarmed */
-static void
-wl_timer_heap_arm(struct wl_timer_heap *timers,
-		  struct wl_event_source_timer *source,
-		  struct timespec deadline)
-{
-	assert(source->heap_idx == -1);
-
-	source->deadline = deadline;
-	timers->data[timers->active] = source;
-	source->heap_idx = timers->active;
-	timers->active++;
-	heap_sift_up(timers->data, source);
-}
-
-
-static int
-wl_timer_heap_dispatch(struct wl_timer_heap *timers)
-{
-	struct timespec now;
-	struct wl_event_source_timer *root;
-	struct wl_event_source_timer *list_cursor = NULL, *list_tail = NULL;
-
-	clock_gettime(CLOCK_MONOTONIC, &now);
-
-	while (timers->active > 0) {
-		root = timers->data[0];
-		if (time_lt(now, root->deadline))
-			break;
-
-		wl_timer_heap_disarm(timers, root);
-
-		if (list_cursor == NULL)
-			list_cursor = root;
-		else
-			list_tail->next_due = root;
-		list_tail = root;
-	}
-	if (list_tail)
-		list_tail->next_due = NULL;
-
-	if (timers->active > 0) {
-		if (set_timer(timers->base.fd, timers->data[0]->deadline) < 0)
-			return -1;
-	} else {
-		if (clear_timer(timers->base.fd) < 0)
-			return -1;
-	}
-
-	/* Execute precisely the functions for events before `now`, in order.
-	 * Because wl_event_loop_dispatch ignores return codes, do the same
-	 * here as well */
-	for (; list_cursor; list_cursor = list_cursor->next_due) {
-		if (list_cursor->base.fd != TIMER_REMOVED)
-			list_cursor->func(list_cursor->base.data);
-	}
-
-	return 0;
-}
-
-static int
 wl_event_source_timer_dispatch(struct wl_event_source *source,
 			       struct epoll_event *ep)
 {
-	struct wl_event_source_timer *timer;
+	struct wl_event_source_timer *timer_source =
+		(struct wl_event_source_timer *) source;
+	uint64_t expires;
+	int len;
 
-	timer = wl_container_of(source, timer, base);
-	return timer->func(timer->base.data);
+	len = read(source->fd, &expires, sizeof expires);
+	if (!(len == -1 && errno == EAGAIN) && len != sizeof expires)
+		/* Is there anything we can do here?  Will this ever happen? */
+		wl_log("timerfd read error: %s\n", strerror(errno));
+
+	return timer_source->func(timer_source->base.data);
 }
 
 struct wl_event_source_interface timer_source_interface = {
 	wl_event_source_timer_dispatch,
 };
 
-/** \endcond */
-
 /** Create a timer event source
  *
  * \param loop The event loop that will process the new source.
@@ -565,30 +260,16 @@ wl_event_loop_add_timer(struct wl_event_loop *loop,
 {
 	struct wl_event_source_timer *source;
 
-	if (wl_timer_heap_ensure_timerfd(&loop->timers) < 0)
-		return NULL;
-
 	source = malloc(sizeof *source);
 	if (source == NULL)
 		return NULL;
 
 	source->base.interface = &timer_source_interface;
-	source->base.fd = -1;
+	source->base.fd = timerfd_create(CLOCK_MONOTONIC,
+					 TFD_CLOEXEC | TFD_NONBLOCK);
 	source->func = func;
-	source->base.loop = loop;
-	source->base.data = data;
-	wl_list_init(&source->base.link);
-	source->next_due = NULL;
-	source->deadline.tv_sec = 0;
-	source->deadline.tv_nsec = 0;
-	source->heap_idx = -1;
 
-	if (wl_timer_heap_reserve(&loop->timers) < 0) {
-		free(source);
-		return NULL;
-	}
-
-	return &source->base;
+	return add_source(loop, &source->base, WL_EVENT_READABLE, data);
 }
 
 /** Arm or disarm a timer
@@ -610,51 +291,15 @@ wl_event_loop_add_timer(struct wl_event_loop *loop,
 WL_EXPORT int
 wl_event_source_timer_update(struct wl_event_source *source, int ms_delay)
 {
-	struct wl_event_source_timer *tsource =
-		wl_container_of(source, tsource, base);
-	struct wl_timer_heap *timers = &tsource->base.loop->timers;
+	struct itimerspec its;
 
-	if (ms_delay > 0) {
-		struct timespec deadline;
+	its.it_interval.tv_sec = 0;
+	its.it_interval.tv_nsec = 0;
+	its.it_value.tv_sec = ms_delay / 1000;
+	its.it_value.tv_nsec = (ms_delay % 1000) * 1000 * 1000;
+	if (timerfd_settime(source->fd, 0, &its, NULL) < 0)
+		return -1;
 
-		clock_gettime(CLOCK_MONOTONIC, &deadline);
-
-		deadline.tv_nsec += (ms_delay % 1000) * 1000000L;
-		deadline.tv_sec += ms_delay / 1000;
-		if (deadline.tv_nsec >= 1000000000L) {
-			deadline.tv_nsec -= 1000000000L;
-			deadline.tv_sec += 1;
-		}
-
-		if (tsource->heap_idx == -1) {
-			wl_timer_heap_arm(timers, tsource, deadline);
-		} else if (time_lt(deadline, tsource->deadline)) {
-			tsource->deadline = deadline;
-			heap_sift_up(timers->data, tsource);
-		} else {
-			tsource->deadline = deadline;
-			heap_sift_down(timers->data, timers->active, tsource);
-		}
-
-		if (tsource->heap_idx == 0) {
-			/* Only update the timerfd if the new deadline is
-			 * the earliest */
-			if (set_timer(timers->base.fd, deadline) < 0)
-				return -1;
-		}
-	} else {
-		if (tsource->heap_idx == -1)
-			return 0;
-		wl_timer_heap_disarm(timers, tsource);
-
-		if (timers->active == 0) {
-			/* Only update the timerfd if this was the last
-			 * active timer */
-			if (clear_timer(timers->base.fd) < 0)
-				return -1;
-		}
-	}
-
 	return 0;
 }
 
@@ -838,17 +483,6 @@ wl_event_source_remove(struct wl_event_source *source)
 		source->fd = -1;
 	}
 
-	if (source->interface == &timer_source_interface &&
-	    source->fd != TIMER_REMOVED) {
-		/* Disarm the timer (and the loop's timerfd, if necessary),
-		 * before removing its space in the loop timer heap */
-		wl_event_source_timer_update(source, 0);
-		wl_timer_heap_unreserve(&loop->timers);
-		/* Set the fd field to to indicate that the timer should NOT
-		 * be dispatched in `wl_event_loop_dispatch` */
-		source->fd = TIMER_REMOVED;
-	}
-
 	wl_list_remove(&source->link);
 	wl_list_insert(&loop->destroy_list, &source->link);
 
@@ -900,8 +534,6 @@ wl_event_loop_create(void)
 
 	wl_signal_init(&loop->destroy_signal);
 
-	wl_timer_heap_init(&loop->timers, loop);
-
 	return loop;
 }
 
@@ -924,7 +556,6 @@ wl_event_loop_destroy(struct wl_event_loop *loop)
 	wl_signal_emit(&loop->destroy_signal, loop);
 
 	wl_event_loop_process_destroy_list(loop);
-	wl_timer_heap_release(&loop->timers);
 	close(loop->epoll_fd);
 	free(loop);
 }
@@ -975,7 +606,7 @@ wl_event_loop_dispatch_idle(struct wl_event_loop *loop
  *
  * \param loop The event loop whose sources to wait for.
  * \param timeout The polling timeout in milliseconds.
- * \return 0 for success, -1 for polling (or timer update) error.
+ * \return 0 for success, -1 for polling error.
  *
  * All the associated event sources are polled. This function blocks until
  * any event source delivers an event (idle sources excluded), or the timeout
@@ -997,29 +628,12 @@ wl_event_loop_dispatch(struct wl_event_loop *loop, int
 	struct epoll_event ep[32];
 	struct wl_event_source *source;
 	int i, count;
-	bool has_timers = false;
 
 	wl_event_loop_dispatch_idle(loop);
 
 	count = epoll_wait(loop->epoll_fd, ep, ARRAY_LENGTH(ep), timeout);
 	if (count < 0)
 		return -1;
-
-	for (i = 0; i < count; i++) {
-		source = ep[i].data.ptr;
-		if (source == &loop->timers.base)
-			has_timers = true;
-	}
-
-	if (has_timers) {
-		/* Dispatch timer sources before non-timer sources, so that
-		 * the non-timer sources can not cancel (by calling
-		 * `wl_event_source_timer_update`) the dispatching of the timers
-		 * (Note that timer sources also can't cancel pending non-timer
-		 * sources, since epoll_wait has already been called) */
-		if (wl_timer_heap_dispatch(&loop->timers) < 0)
-			return -1;
-	}
 
 	for (i = 0; i < count; i++) {
 		source = ep[i].data.ptr;
