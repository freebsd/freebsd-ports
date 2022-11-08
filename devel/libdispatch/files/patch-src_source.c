--- src/source.c.orig	2021-09-17 04:54:52 UTC
+++ src/source.c
@@ -1398,11 +1398,11 @@ _dispatch_source_debug_attr(dispatch_source_t ds, char
 	dispatch_source_refs_t dr = ds->ds_refs;
 	dispatch_queue_flags_t dqf = _dispatch_queue_atomic_flags(ds);
 	dispatch_unote_state_t du_state = _dispatch_unote_state(dr);
-	return dsnprintf(buf, bufsiz, "target = %s[%p], ident = 0x%x, "
+	return dsnprintf(buf, bufsiz, "target = %s[%p], ident = 0x%llx, "
 			"mask = 0x%x, pending_data = 0x%llx, registered = %d, "
 			"armed = %d, %s%s%s",
 			target && target->dq_label ? target->dq_label : "", target,
-			dr->du_ident, dr->du_fflags, (unsigned long long)dr->ds_pending_data,
+			(unsigned long long)dr->du_ident, dr->du_fflags, (unsigned long long)dr->ds_pending_data,
 			_du_state_registered(du_state), _du_state_armed(du_state),
 			(dqf & DSF_CANCELED) ? "cancelled, " : "",
 			(dqf & DSF_NEEDS_EVENT) ? "needs-event, " : "",
