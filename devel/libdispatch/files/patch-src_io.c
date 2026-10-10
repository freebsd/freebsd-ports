--- src/io.c.orig	2026-05-01 02:25:26 UTC
+++ src/io.c
@@ -2357,7 +2357,7 @@ _dispatch_operation_advise(dispatch_operation_t op, si
 		case ESPIPE: break; // fd refers to a pipe or FIFO
 		default: (void)dispatch_assume_zero(err); break;
 	}
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 	(void)err;
 #else
 #error "_dispatch_operation_advise not implemented on this platform"
