--- src/internal.h.orig	2025-03-07 00:50:44 UTC
+++ src/internal.h
@@ -277,6 +277,9 @@ upcast(dispatch_object_t dou)
 #include <sys/sysctl.h>
 #include <sys/queue.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/eventfd.h>
+#endif // __FreeBSD__
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/mman.h>
@@ -475,12 +478,10 @@ struct dispatch_unote_class_s;
 
 struct dispatch_unote_class_s;
 
-#if HAVE_MACH
 DISPATCH_NOINLINE DISPATCH_COLD
 void _dispatch_bug_kevent_client(const char *msg, const char *filter,
 		const char *operation, int err, uint64_t ident, uint64_t udata,
 		struct dispatch_unote_class_s *du);
-#endif // HAVE_MACH
 
 DISPATCH_NOINLINE DISPATCH_COLD
 void _dispatch_bug_kevent_vanished(struct dispatch_unote_class_s *du);
