--- src/event/event.c.orig	2021-09-17 04:54:52 UTC
+++ src/event/event.c
@@ -766,9 +766,9 @@ _dispatch_timer_heap_update(dispatch_timer_heap_t dth,
 #pragma mark timer unote
 
 #define _dispatch_timer_du_debug(what, du) \
-		_dispatch_debug("kevent-source[%p]: %s kevent[%p] { ident = 0x%x }", \
+		_dispatch_debug("kevent-source[%p]: %s kevent[%p] { ident = 0x%llx }", \
 				_dispatch_wref2ptr((du)->du_owner_wref), what, \
-				(du), (du)->du_ident)
+				(du), (unsigned long long)(du)->du_ident)
 
 DISPATCH_ALWAYS_INLINE
 static inline unsigned int
@@ -792,7 +792,7 @@ _dispatch_timer_unote_disarm(dispatch_timer_source_ref
 _dispatch_timer_unote_disarm(dispatch_timer_source_refs_t dt,
 		dispatch_timer_heap_t dth)
 {
-	uint32_t tidx = dt->du_ident;
+	uint32_t tidx = (uint32_t)dt->du_ident;
 
 	dispatch_assert(_dispatch_unote_armed(dt));
 	_dispatch_timer_heap_remove(&dth[tidx], dt);
