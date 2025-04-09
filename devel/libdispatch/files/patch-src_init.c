--- src/init.c.orig	2025-03-07 00:50:44 UTC
+++ src/init.c
@@ -964,7 +964,6 @@ _dispatch_continuation_get_function_symbol(dispatch_co
 	return dc->dc_func;
 }
 
-#if HAVE_MACH
 void
 _dispatch_bug_kevent_client(const char *msg, const char *filter,
 		const char *operation, int err, uint64_t ident, uint64_t udata,
@@ -1008,7 +1007,6 @@ _dispatch_bug_kevent_client(const char *msg, const cha
 				msg, strerror(err), err, udata, filter, ident, ident, func);
 	}
 }
-#endif // HAVE_MACH
 
 #if RDAR_49023449
 
@@ -1051,7 +1049,7 @@ _dispatch_bug_kevent_vanished(dispatch_unote_t du)
 			"{ %p[%s], ident: %" PRIdPTR " / 0x%" PRIxPTR ", handler: %p }",
 			dux_type(du._du)->dst_kind, dou._dq,
 			dou._dq->dq_label ? dou._dq->dq_label : "<unknown>",
-			du._du->du_ident, du._du->du_ident, func);
+			(intptr_t)du._du->du_ident, (uintptr_t)du._du->du_ident, func);
 }
 
 #endif // RDAR_49023449
@@ -1157,7 +1155,7 @@ _dispatch_logv_init(void *context DISPATCH_UNUSED)
 #else
 			dprintf(dispatch_logfile, "=== log file opened for %s[%u] at "
 					"%ld.%06u ===\n", getprogname() ?: "", getpid(),
-					tv.tv_sec, (int)tv.tv_usec);
+					(time_t)tv.tv_sec, (int)tv.tv_usec);
 #endif
 		}
 	}
