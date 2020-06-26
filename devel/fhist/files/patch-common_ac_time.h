--- common/ac/time.h.orig	2012-07-13 04:47:15 UTC
+++ common/ac/time.h
@@ -26,7 +26,7 @@
  * Catch-22: Dec Alpha OSF/1: need to include time.h before sys/time.h
  * before time.h
  */
-#ifdef __alpha__
+#ifdef __osf1__
 #ifndef _CLOCK_ID_T
 #define _CLOCK_ID_T
 typedef int clockid_t;
