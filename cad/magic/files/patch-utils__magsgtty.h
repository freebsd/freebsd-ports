--- ./utils/magsgtty.h.orig	2011-09-02 12:36:19.000000000 +0200
+++ ./utils/magsgtty.h	2011-09-02 12:39:00.000000000 +0200
@@ -21,14 +21,10 @@
 #ifndef	_MAGSGTTY_H
 #define _MAGSGTTY_H
 
-#if !defined(SYSV) && !defined(CYGWIN)
-# ifdef	ALPHA
-# undef MAX
-# undef MIN
-# endif
-#include <sgtty.h>
+#if defined(__FreeBSD__)
+#include <termios.h>
 #else
-#include <termio.h>
+#include <sgtty.h>
 #endif
 
 #endif	/* _MAGSGTTY_H */
