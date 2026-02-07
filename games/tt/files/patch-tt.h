--- tt.h.orig	Sat Sep 13 09:20:29 2003
+++ tt.h	Sat Sep 13 09:48:57 2003
@@ -20,7 +20,7 @@
 |*									   *|
 \***************************************************************************/
 
-#undef LOCKF			/* Use lockf(3) instead of open(O_EXCL) */
+#define LOCKF			/* Use lockf(3) instead of open(O_EXCL) */
 
 /***************************************************************************\
 |*									   *|
@@ -187,5 +187,5 @@
 /*--------------------------------------------------------------------------*/
 
 /* This is probably still the most portable way ... */
-extern int read(), close(), sleep(), unlink(), write(), getuid();
-extern void usleep();
+//extern int read(), close(), sleep(), unlink(), write(), getuid();
+//extern void usleep();
