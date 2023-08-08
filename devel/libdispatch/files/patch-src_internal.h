--- src/internal.h.orig	2021-09-17 04:54:52 UTC
+++ src/internal.h
@@ -475,12 +475,10 @@ struct dispatch_unote_class_s;
 
 struct dispatch_unote_class_s;
 
-#if HAVE_MACH
 DISPATCH_NOINLINE DISPATCH_COLD
 void _dispatch_bug_kevent_client(const char *msg, const char *filter,
 		const char *operation, int err, uint64_t ident, uint64_t udata,
 		struct dispatch_unote_class_s *du);
-#endif // HAVE_MACH
 
 DISPATCH_NOINLINE DISPATCH_COLD
 void _dispatch_bug_kevent_vanished(struct dispatch_unote_class_s *du);
