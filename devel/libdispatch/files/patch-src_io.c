--- src/io.c.orig	2021-09-17 04:54:52 UTC
+++ src/io.c
@@ -22,7 +22,7 @@
 
 #if defined(__FreeBSD__)
 #include <fcntl.h>
-#define F_RDADVISE F_RDAHEAD
+//#define F_RDADVISE F_RDAHEAD
 #endif
 
 #ifndef DISPATCH_IO_DEBUG
@@ -2308,7 +2308,7 @@ _dispatch_operation_advise(dispatch_operation_t op, si
 		default: (void)dispatch_assume_zero(err); break;
 	}
 #else
-#error "_dispatch_operation_advise not implemented on this platform"
+	(void)err;
 #endif // defined(F_RDADVISE)
 #endif // defined(_WIN32)
 }
