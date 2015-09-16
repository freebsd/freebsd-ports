--- compiler.h.orig	2015-03-13 12:36:31 UTC
+++ compiler.h
@@ -46,9 +46,9 @@
 
 #ifndef S_SPLINT_S
 #ifdef HAVE_STDATOMIC_H
-#ifndef __COVERITY__	/* Coverity is confused by a GNU typedef */
+#if !defined(__COVERITY__) && !defined(__cplusplus)
 #include <stdatomic.h>
-#endif /* __COVERITY__ */
+#endif /* __COVERITY__ || __cplusplus */
 #endif /* HAVE_STDATOMIC_H */
 #endif /* S_SPLINT_S */
 
