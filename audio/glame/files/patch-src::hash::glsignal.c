--- src/hash/glsignal.c.orig	Sat Oct 23 22:14:22 2004
+++ src/hash/glsignal.c	Sat Dec 11 21:30:33 2004
@@ -63,7 +63,11 @@
 
 	glame_list_foreach(&dest->handlers, glsig_handler_t, list, h) {
 		va_list vac;
+#if defined(__FreeBSD__) && defined(__GNUC__) && (__GNUC__ < 3)
+		vac = va;
+#else
 		va_copy(vac, va);
+#endif
 		_glsig_handler_exec(h, sig, vac);
 		va_end(vac);
 	}
