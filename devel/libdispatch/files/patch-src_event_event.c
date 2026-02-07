--- src/event/event.c.orig	2023-06-15 00:55:45 UTC
+++ src/event/event.c
@@ -792,7 +792,7 @@ _dispatch_timer_unote_disarm(dispatch_timer_source_ref
 _dispatch_timer_unote_disarm(dispatch_timer_source_refs_t dt,
 		dispatch_timer_heap_t dth)
 {
-	uint32_t tidx = dt->du_ident;
+	uint32_t tidx = (uint32_t)dt->du_ident;
 
 	dispatch_assert(_dispatch_unote_armed(dt));
 	_dispatch_timer_heap_remove(&dth[tidx], dt);
