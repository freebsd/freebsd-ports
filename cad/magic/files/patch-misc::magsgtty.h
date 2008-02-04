--- misc/magsgtty.h	2001-09-21 17:15:45.000000000 +0200
+++ misc/magsgtty.h	2008-02-04 19:28:46.000000000 +0100
@@ -20,7 +20,9 @@
 
 #ifndef	_MAGSGTTY
 
-#if !defined(SYSV) && !defined(CYGWIN)
+#ifdef __FreeBSD__
+#include <termios.h>
+#elif !defined(SYSV) && !defined(CYGWIN)
 # ifdef	ALPHA
 # undef MAX
 # undef MIN
