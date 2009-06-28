--- libs/std/sys.c.orig	2009-06-19 00:08:19.000000000 +0900
+++ libs/std/sys.c	2009-06-19 00:11:42.000000000 +0900
@@ -35,7 +35,9 @@
 #	include <termios.h>
 #	include <sys/time.h>
 #	include <sys/times.h>
+#ifndef __FreeBSD__
 #	include <xlocale.h>
+#endif
 #endif
 
 #ifdef NEKO_MAC
@@ -123,6 +125,9 @@
 	<doc>Set the locale for LC_TIME, returns true on success</doc>
 **/
 static value set_time_locale( value l ) {
+#ifdef __FreeBSD__
+#undef NEKO_POSIX
+#endif
 #ifdef NEKO_POSIX
 	locale_t lc, old;
 	val_check(l,string);
