--- src/init.c.orig	2021-09-17 04:54:52 UTC
+++ src/init.c
@@ -961,7 +961,6 @@ _dispatch_continuation_get_function_symbol(dispatch_co
 	return dc->dc_func;
 }
 
-#if HAVE_MACH
 void
 _dispatch_bug_kevent_client(const char *msg, const char *filter,
 		const char *operation, int err, uint64_t ident, uint64_t udata,
@@ -1005,7 +1004,6 @@ _dispatch_bug_kevent_client(const char *msg, const cha
 				msg, strerror(err), err, udata, filter, ident, ident, func);
 	}
 }
-#endif // HAVE_MACH
 
 #if RDAR_49023449
 
@@ -1048,7 +1046,7 @@ _dispatch_bug_kevent_vanished(dispatch_unote_t du)
 			"{ %p[%s], ident: %" PRIdPTR " / 0x%" PRIxPTR ", handler: %p }",
 			dux_type(du._du)->dst_kind, dou._dq,
 			dou._dq->dq_label ? dou._dq->dq_label : "<unknown>",
-			du._du->du_ident, du._du->du_ident, func);
+			(intptr_t)du._du->du_ident, (uintptr_t)du._du->du_ident, func);
 }
 
 #endif // RDAR_49023449
@@ -1153,8 +1151,8 @@ _dispatch_logv_init(void *context DISPATCH_UNUSED)
 			}
 #else
 			dprintf(dispatch_logfile, "=== log file opened for %s[%u] at "
-					"%ld.%06u ===\n", getprogname() ?: "", getpid(),
-					tv.tv_sec, (int)tv.tv_usec);
+					"%lld.%06u ===\n", getprogname() ?: "", getpid(),
+					(time_t)tv.tv_sec, (int)tv.tv_usec);
 #endif
 		}
 	}
