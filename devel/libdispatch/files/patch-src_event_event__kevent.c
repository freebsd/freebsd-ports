--- src/event/event_kevent.c.orig	2021-09-17 04:54:52 UTC
+++ src/event/event_kevent.c
@@ -101,8 +101,12 @@ _evfiltstr(short filt)
 	_evfilt2(EVFILT_MACHPORT);
 	_evfilt2(DISPATCH_EVFILT_MACH_NOTIFICATION);
 #endif
+#ifdef EVFILT_FS
 	_evfilt2(EVFILT_FS);
+#endif
+#ifdef EVFILT_USER
 	_evfilt2(EVFILT_USER);
+#endif
 #ifdef EVFILT_SOCK
 	_evfilt2(EVFILT_SOCK);
 #endif
@@ -236,9 +240,9 @@ dispatch_kevent_debug(const char *verb, const dispatch
 
 #define _dispatch_du_debug(what, du) \
 		_dispatch_debug("kevent-source[%p]: %s kevent[%p] " \
-				"{ filter = %s, ident = 0x%x }", \
+				"{ filter = %s, ident = 0x%llx }", \
 				_dispatch_wref2ptr((du)->du_owner_wref), what, \
-				(du), _evfiltstr((du)->du_filter), (du)->du_ident)
+				(du), _evfiltstr((du)->du_filter), (unsigned long long)(du)->du_ident)
 
 #if DISPATCH_MACHPORT_DEBUG
 #ifndef MACH_PORT_TYPE_SPREQUEST
@@ -388,8 +392,10 @@ _dispatch_kevent_print_error(dispatch_kevent_t ke)
 	switch (ke->data) {
 	case 0:
 		return;
+#if DISPATCH_USE_KEVENT_QOS
 	case ERANGE: /* A broken QoS was passed to kevent_id() */
 		DISPATCH_INTERNAL_CRASH(ke->qos, "Invalid kevent priority");
+#endif
 	default:
 		// log the unexpected error
 		_dispatch_bug_kevent_client("kevent", _evfiltstr(ke->filter),
@@ -397,7 +403,7 @@ _dispatch_kevent_print_error(dispatch_kevent_t ke)
 				ke->flags & EV_DELETE ? "delete" :
 				ke->flags & EV_ADD ? "add" :
 				ke->flags & EV_ENABLE ? "enable" : "monitor",
-				(int)ke->data, ke->ident, ke->udata, du);
+				(int)ke->data, ke->ident, (uint64_t)ke->udata, du);
 	}
 }
 
@@ -528,11 +534,17 @@ _dispatch_kevent_merge_muxed(dispatch_kevent_t ke)
 	}
 }
 
+#define DISPATCH_KEVENT_ERSATZ_EVFILT_USER_MASK 0xfffffe00
+
 DISPATCH_NOINLINE
 static void
 _dispatch_kevent_drain(dispatch_kevent_t ke)
 {
+#ifdef EVFILT_USER
 	if (ke->filter == EVFILT_USER) {
+#else
+	if (ke->filter == EVFILT_TIMER && ke->ident == DISPATCH_KEVENT_ERSATZ_EVFILT_USER_MASK) {
+#endif
 		_dispatch_kevent_mgr_debug("received", ke);
 		return;
 	}
@@ -579,10 +591,17 @@ _dispatch_kq_create(intptr_t *fd_ptr)
 _dispatch_kq_create(intptr_t *fd_ptr)
 {
 	static const dispatch_kevent_s kev = {
+#ifdef EVFILT_USER
 		.ident = 1,
 		.filter = EVFILT_USER,
 		.flags = EV_ADD|EV_CLEAR,
 		.udata = (dispatch_kevent_udata_t)DISPATCH_WLH_MANAGER,
+#else
+		.ident = DISPATCH_KEVENT_ERSATZ_EVFILT_USER_MASK,
+		.filter = EVFILT_TIMER,
+		.flags = EV_ADD|EV_DISABLE,
+		.data = 1,
+#endif
 	};
 	int kqfd;
 
@@ -591,7 +610,6 @@ _dispatch_kq_create(intptr_t *fd_ptr)
 	guardid_t guard = (uintptr_t)fd_ptr;
 	kqfd = guarded_kqueue_np(&guard, GUARD_CLOSE | GUARD_DUP);
 #else
-	(void)guard_ptr;
 	kqfd = kqueue();
 #endif
 	if (kqfd == -1) {
@@ -727,6 +745,10 @@ retry:
 		(void)avail;
 		const struct timespec timeout_immediately = {}, *timeout = NULL;
 		if (flags & KEVENT_FLAG_IMMEDIATE) timeout = &timeout_immediately;
+#ifdef EVFILT_USER
+		const struct timespec timeout_1ms = {.tv_sec = 0, .tv_nsec = 1000000};
+		if (ke->ident == DISPATCH_KEVENT_ERSATZ_EVFILT_USER_MASK) timeout = &timeout_1ms;
+#endif
 		r = kevent(kqfd, ke, n, ke_out, n_out, timeout);
 #endif
 #if DISPATCH_USE_KEVENT_WORKLOOP
@@ -743,7 +765,7 @@ retry:
 		switch (err) {
 		case ENOMEM:
 			_dispatch_temporary_resource_shortage();
-			/* FALLTHROUGH */
+			DISPATCH_FALLTHROUGH;
 		case EINTR:
 			goto retry;
 		case EBADF:
@@ -754,7 +776,7 @@ retry:
 					(flags & KEVENT_FLAG_DYNAMIC_KQ_MUST_EXIST)) {
 				return 0;
 			}
-			/* FALLTHROUGH */
+			DISPATCH_FALLTHROUGH;
 #endif // DISPATCH_USE_KEVENT_WORKLOOP
 		default:
 			DISPATCH_CLIENT_CRASH(err, "Unexpected error from kevent");
@@ -786,9 +808,15 @@ _dispatch_kq_drain(dispatch_wlh_t wlh, dispatch_kevent
 
 #if DISPATCH_DEBUG
 	for (r = 0; r < n; r++) {
+#ifdef EVFILT_USER
 		if (ke[r].filter != EVFILT_USER || DISPATCH_MGR_QUEUE_DEBUG) {
 			_dispatch_kevent_debug_n(NULL, ke + r, r, n);
 		}
+#else
+		if (DISPATCH_MGR_QUEUE_DEBUG) {
+			_dispatch_kevent_debug_n(NULL, ke + r, r, n);
+		}
+#endif
 	}
 #endif
 
@@ -860,7 +888,6 @@ _dispatch_kq_unote_set_kevent(dispatch_unote_t _du, di
 				du->du_priority),
 #endif
 	};
-	(void)pp; // if DISPATCH_USE_KEVENT_QOS == 0
 }
 
 DISPATCH_ALWAYS_INLINE
@@ -921,9 +948,13 @@ _dispatch_kq_deferred_update(dispatch_wlh_t wlh, dispa
 				ke->udata);
 		dispatch_kevent_t dk = _dispatch_kq_deferred_reuse_slot(wlh, ddi, slot);
 		*dk = *ke;
+#ifdef EVFILT_USER
 		if (ke->filter != EVFILT_USER) {
 			_dispatch_kevent_mgr_debug("deferred", ke);
 		}
+#else
+		_dispatch_kevent_mgr_debug("deferred", ke);
+#endif
 	} else {
 		_dispatch_kq_update_one(wlh, ke);
 	}
@@ -985,6 +1016,7 @@ _dispatch_sync_ipc_handoff_end(dispatch_wlh_t wlh, mac
 }
 #endif
 
+#if DISPATCH_HAVE_DIRECT_KNOTES
 DISPATCH_NOINLINE
 static bool
 _dispatch_kq_unote_update(dispatch_wlh_t wlh, dispatch_unote_t _du,
@@ -1055,6 +1087,7 @@ done:
 	dispatch_assume_zero(r);
 	return true;
 }
+#endif
 
 #pragma mark dispatch_muxnote_t
 
@@ -1283,6 +1316,7 @@ _dispatch_unote_unregister_direct(dispatch_unote_t du,
 #pragma mark -
 #pragma mark dispatch_event_loop
 
+#if DISPATCH_USE_KEVENT_WORKLOOP
 enum {
 	DISPATCH_WORKLOOP_ASYNC,
 	DISPATCH_WORKLOOP_ASYNC_FROM_SYNC,
@@ -1316,6 +1350,7 @@ static char const * const _dispatch_workloop_actions[]
 	[DISPATCH_WORKLOOP_SYNC_WAKE]                   = "sync-wake",
 	[DISPATCH_WORKLOOP_SYNC_END]                    = "sync-end",
 };
+#endif
 
 void
 _dispatch_event_loop_atfork_child(void)
@@ -1410,7 +1445,7 @@ _dispatch_kq_fill_workloop_event(dispatch_kevent_t ke,
 	switch (which) {
 	case DISPATCH_WORKLOOP_ASYNC_FROM_SYNC:
 		fflags |= NOTE_WL_END_OWNERSHIP;
-		/* FALLTHROUGH */
+		DISPATCH_FALLTHROUGH;
 	case DISPATCH_WORKLOOP_ASYNC:
 	case DISPATCH_WORKLOOP_ASYNC_DISCOVER_SYNC:
 	case DISPATCH_WORKLOOP_ASYNC_QOS_UPDATE:
@@ -1434,10 +1469,10 @@ _dispatch_kq_fill_workloop_event(dispatch_kevent_t ke,
 
 	case DISPATCH_WORKLOOP_ASYNC_LEAVE_FROM_SYNC:
 		fflags |= NOTE_WL_END_OWNERSHIP;
-		/* FALLTHROUGH */
+		DISPATCH_FALLTHROUGH;
 	case DISPATCH_WORKLOOP_ASYNC_LEAVE_FROM_TRANSFER:
 		fflags |= NOTE_WL_IGNORE_ESTALE;
-		/* FALLTHROUGH */
+		DISPATCH_FALLTHROUGH;
 	case DISPATCH_WORKLOOP_ASYNC_LEAVE:
 		dispatch_assert(!_dq_state_is_enqueued_on_target(dq_state));
 		action = EV_ADD | EV_DELETE | EV_ENABLE;
@@ -1881,10 +1916,17 @@ _dispatch_event_loop_poke(dispatch_wlh_t wlh, uint64_t
 {
 	if (wlh == DISPATCH_WLH_MANAGER) {
 		dispatch_kevent_s ke = (dispatch_kevent_s){
+#ifdef EVFILT_USER
 			.ident  = 1,
 			.filter = EVFILT_USER,
 			.fflags = NOTE_TRIGGER,
 			.udata = (dispatch_kevent_udata_t)DISPATCH_WLH_MANAGER,
+#else
+			.ident = DISPATCH_KEVENT_ERSATZ_EVFILT_USER_MASK,
+			.filter = EVFILT_TIMER,
+			.flags = EV_ADD|EV_ENABLE,
+			.data = 1
+#endif
 		};
 		return _dispatch_kq_deferred_update(DISPATCH_WLH_ANON, &ke);
 	} else if (wlh && wlh != DISPATCH_WLH_ANON) {
@@ -2357,6 +2399,12 @@ _dispatch_event_loop_timer_arm(dispatch_timer_heap_t d
 		target += range.leeway;
 		range.leeway = 0;
 	}
+#if !NOTE_ABSOLUTE
+	target = range.delay;
+#if defined(__FreeBSD__)
+	target /= 1000000;
+#endif
+#endif
 
 	_dispatch_event_loop_timer_program(dth, tidx, target, range.leeway,
 			EV_ADD | EV_ENABLE);
@@ -2445,6 +2493,7 @@ const dispatch_source_type_s _dispatch_source_type_vno
 	.dst_merge_evt  = _dispatch_source_merge_evt,
 };
 
+#ifdef EVFILT_FS
 const dispatch_source_type_s _dispatch_source_type_vfs = {
 	.dst_kind       = "vfs",
 	.dst_filter     = EVFILT_FS,
@@ -2477,6 +2526,7 @@ const dispatch_source_type_s _dispatch_source_type_vfs
 	.dst_create     = _dispatch_unote_create_without_handle,
 	.dst_merge_evt  = _dispatch_source_merge_evt,
 };
+#endif
 
 #ifdef EVFILT_SOCK
 const dispatch_source_type_s _dispatch_source_type_sock = {
