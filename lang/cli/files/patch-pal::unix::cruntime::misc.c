
$FreeBSD$

--- pal/unix/cruntime/misc.c	2002/03/28 19:08:00	1.1
+++ pal/unix/cruntime/misc.c	2002/03/28 19:26:36
@@ -31,6 +31,8 @@
    collision for va_start and va_end */
 #include <stdarg.h>
 
+#define time_t DUMMY_time_t
+
 SET_DEFAULT_DEBUG_CHANNEL(CRT);
 
 static const int STR_TIME_SIZE =26;
