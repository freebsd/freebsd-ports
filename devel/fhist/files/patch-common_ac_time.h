
$FreeBSD$

--- common/ac/time.h.orig	Wed Dec 18 02:09:57 2002
+++ common/ac/time.h	Wed Dec 18 02:10:04 2002
@@ -29,7 +29,7 @@
  * Catch-22: Dec Alpha OSF/1: need to include time.h before sys/time.h
  * before time.h
  */
-#ifdef __alpha__
+#ifdef __osf1__
 #ifndef _CLOCK_ID_T
 #define _CLOCK_ID_T
 typedef int clockid_t;
